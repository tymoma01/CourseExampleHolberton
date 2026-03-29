import asyncio
import random
import time

async def producer(queue: asyncio.Queue, n_items: int):
    """Produce n_items and put them into the queue."""

    for i in range(n_items):
        await asyncio.sleep(random.uniform(0.1, 0.4))  # simulate work
        item = f"job-{i}"
        print(f"[PRODUCER] produced {item}")
        await queue.put(item)   # blocks if the queue is full (no max size here, so never blocks)

    # send one None per consumer to signal them to stop (sentinel / poison pill pattern)
    n_consumers = 2
    for _ in range(n_consumers):
        await queue.put(None)
    print("[PRODUCER] finished")

async def consumer(name: str, queue: asyncio.Queue):
    """Take items from the queue and process them."""

    while True:
        item = await queue.get()   # blocks until an item is available

        if item is None:   # received the stop signal — exit the loop
            print(f"[{name}] received stop signal")
            queue.task_done()   # must always call task_done(), even for the sentinel
            break

        print(f"[{name}] processing {item}...")
        await asyncio.sleep(random.uniform(0.2, 0.6))   # simulate processing time
        print(f"[{name}] done with {item}")
        queue.task_done()   # notify the queue that this item has been processed

async def main():
    queue = asyncio.Queue()
    start = time.perf_counter()

    # create_task() schedules the coroutine immediately without waiting for it to finish
    # this lets producer and consumers run concurrently
    producer_task = asyncio.create_task(producer(queue, n_items=5))
    consumers = [
        asyncio.create_task(consumer("CONSUMER-1", queue)),
        asyncio.create_task(consumer("CONSUMER-2", queue)),
    ]

    await producer_task   # wait for the producer to finish producing all items
    await queue.join()    # wait until every item in the queue has been processed (task_done called for each)

    # At this point, the producer has already sent sentinels; wait for consumers to exit
    await asyncio.gather(*consumers)

    elapsed = time.perf_counter() - start
    print(f"Total time: {elapsed:.2f}s")

asyncio.run(main())

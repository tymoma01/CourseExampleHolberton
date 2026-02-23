import asyncio
import random
import time

async def producer(queue: asyncio.Queue, n_items: int):
    """Produce n_items and put them into the queue."""

    for i in range(n_items):
        await asyncio.sleep(random.uniform(0.1, 0.4))  # simulate work
        item = f"job-{i}"
        print(f"[PRODUCER] produced {item}")
        await queue.put(item)

    # "we're done" values
    n_consumers = 2
    for _ in range(n_consumers):
        await queue.put(None)  # sentinel / poison pill
    print("[PRODUCER] finished")

async def consumer(name: str, queue: asyncio.Queue):
    """Take items from the queue and process them."""

    while True:
        item = await queue.get()
        
        if item is None:  # -> stop this consumer
            print(f"[{name}] received stop signal")
            queue.task_done()
            break

        print(f"[{name}] processing {item}...")
        await asyncio.sleep(random.uniform(0.2, 0.6))
        print(f"[{name}] done with {item}")
        queue.task_done()

async def main():
    queue = asyncio.Queue()
    start = time.perf_counter()

    # One producer, two consumers
    producer_task = asyncio.create_task(producer(queue, n_items=5))
    consumers = [
        asyncio.create_task(consumer("CONSUMER-1", queue)),
        asyncio.create_task(consumer("CONSUMER-2", queue)),
    ]

    # Wait until the producer and all queued jobs are done
    await producer_task
    await queue.join()

    # At this point, the producer has already sent sentinels; wait for consumers to exit
    await asyncio.gather(*consumers)

    elapsed = time.perf_counter() - start
    print(f"Total time: {elapsed:.2f}s")

asyncio.run(main())

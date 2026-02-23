import asyncio
import time

async def fake_io_task(name, delay):
    """Simulate a network request or DB query."""

    print(f"[{name}] Starting I/O (delay={delay}s)")

    await asyncio.sleep(delay)

    print(f"[{name}] Finished I/O")
    
    return name

async def run_sequential():
    print("\n--- Sequential version ---")

    start = time.perf_counter()

    await fake_io_task("task-1", 1)
    await fake_io_task("task-2", 2)
    await fake_io_task("task-3", 3)

    elapsed = time.perf_counter() - start

    print(f"Sequential total time: {elapsed:.2f}s")

async def run_concurrent():
    print("\n--- Concurrent version ---")
    start = time.perf_counter()

    results = await asyncio.gather(
        fake_io_task("task-1", 1),
        fake_io_task("task-2", 2),
        fake_io_task("task-3", 3),
    )
    
    elapsed = time.perf_counter() - start
    print(f"Concurrent total time: {elapsed:.2f}s")
    print(f"Results order matches gather order: {results}")

async def main():
    await run_sequential()
    await run_concurrent()

asyncio.run(main())

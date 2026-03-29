import asyncio

async def greet_after(delay, name):
    """Coroutine: waits a bit, then prints a greeting."""

    print(f"[{name}] Preparing greeting...")

    await asyncio.sleep(delay)   # pause this coroutine and yield control to the event loop
                                 # other tasks could run here during the wait

    print(f"[{name}] Hello from greet_after async function!")

async def main():
    print("Starting main()")
    await greet_after(3, "Alice")   # waits 3s before moving on — still sequential
    await greet_after(2, "Bob")     # total time: 3 + 2 = 5s (see gather.py for the concurrent version)
    print("main() finished")

# asyncio.run() starts the event loop and runs main() until it completes
asyncio.run(main())

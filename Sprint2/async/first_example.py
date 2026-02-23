import asyncio

async def greet_after(delay, name):
    """Coroutine: waits a bit, then prints a greeting."""

    print(f"[{name}] Preparing greeting...")

    await asyncio.sleep(delay)   # yields control to the event loop

    print(f"[{name}] Hello from greet_after async function!")

async def main():
    print("Starting main()")
    await greet_after(3, "Alice")
    await greet_after(2, "Bob")
    print("main() finished")

# Start the event loop and run main()
asyncio.run(main())

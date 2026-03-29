# When Should You Use `async` vs Regular Functions in Python?

## When to Use `async`

You should use **`async` ONLY when BOTH conditions are true**:

### **1. The function performs non-blocking I/O**
Typical async-friendly operations:
- HTTP requests (aiohttp, httpx async mode)
- Database operations (with async drivers)
- File I/O (aiofiles)
- WebSockets
- Timers (`await asyncio.sleep`)
- Network servers (FastAPI, aiohttp, websockets)
- Anything that *waits* for an external resource

### **2. You want the program to continue doing other things during the wait**

Async makes your program more responsive by letting other tasks run while waiting.

---

## When *NOT* to Use `async`

### **1. The function does CPU work**
Examples:
- Heavy computations
- Large data processing
- Machine learning steps
- Image or video processing
- Long loops that use the CPU continuously

Using `async` here **blocks the event loop** and slows everything down.

**Use instead:**
- Regular functions  
- Threads (sometimes)  
- Multiprocessing (for parallel CPU work)

---

### **2. The function does not call any async operations**
If there’s nothing to `await`, there is no benefit to making the function async.

---

### **3. The library you use is not async-compatible**
For example, this is wrong:

```python
async def bad():
    r = requests.get("https://api.com")
```


Async does not make things faster.  
It only makes waiting efficient, allowing other tasks to run.  

If a function does work, use a regular function.  

If a function waits, use async.
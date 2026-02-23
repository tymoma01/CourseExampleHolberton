# Introduction to APIs

Welcome to this short course designed to introduce you to the basics of APIs — how they work, how to interact with them, and how to understand their responses.

---

## What Is an API?

### API = Application Programming Interface

An **API** allows two different programs to communicate with each other.  
It acts as a messenger that takes a request from one program, tells another what to do, and returns the result.

APIs usually communicate through the **HTTP protocol** — the same protocol used by websites.

---


## Anatomy of an API Request

Every API request includes:

- **URL** → where the API lives (e.g. `https://api.weather.com`)  
- **Method** → what you want to do (e.g. `GET`, `POST`, `PUT`, `DELETE`)  
- **Headers** → extra information (e.g. authentication or content type)  
- **Body** → the data you send (for `POST` or `PUT` requests)

The API replies with a **response**, usually in **JSON format**:

```json
{
  "city": "Melbourne",
  "temperature": 22,
  "condition": "Sunny"
}
```

---

## CRUD Operations

APIs often follow a pattern called **CRUD**, which stands for:

| Operation | HTTP Method | Purpose | Example |
|------------|--------------|----------|----------|
| Create | POST | Create new data | Add a new user |
| Read | GET | Retrieve data | Get a list of users |
| Update | PUT / PATCH | Modify existing data | Edit a user’s information |
| Delete | DELETE | Remove data | Delete a user |

---

## Using curl

### What Is curl?

**curl** stands for **Client URL**.  
It’s a command-line tool used to send and receive data from a server over the internet.  
Developers use it to test APIs quickly without writing code.

---

### Example: Sending a POST Request

```bash
curl -X POST https://example.com/api/users -H "Content-Type: application/json" -d '{"name": "Alice", "age": 25}'
```

**Explanation:**

| Option | Meaning |
|---------|----------|
| `-X` | Specify the HTTP method (`GET`, `POST`, etc.) |
| `-X POST` | Tells curl to use the POST method |
| `-H` | Adds a header (here, specifying that the content is JSON) |
| `-d` | Sends data in the request body |
| `-i` | Show response headers |
| `-v` | Verbose mode for debugging |
| `-o filename` | Save the response to a file |

---
## HTTP Status Codes

When you send a request to an API, it replies with a status code — a 3-digit number that tells you what happened.

---

### Categories of Status Codes

| Category | Range | Meaning |
|-----------|--------|----------|
| 1xx | 100–199 | Information – “I got your request, still processing.” |
| 2xx | 200–299 | Success – “Everything went fine.” |
| 3xx | 300–399 | Redirection – “Go somewhere else.” |
| 4xx | 400–499 | Client error – “You did something wrong.” |
| 5xx | 500–599 | Server error – “Something’s wrong on our end.” |

---

## 2xx — Success Codes

| Code | Meaning | Example |
|------|----------|----------|
| 200 OK | Request succeeded | GET a list of users |
| 201 Created | A new resource was created | POST a new user |
| 204 No Content | Success, but no response body | DELETE a user |

---

## 3xx — Redirection Codes

| Code | Meaning | Example |
|------|----------|----------|
| 301 Moved Permanently | Resource moved to a new URL | A webpage changed its address |
| 302 Found | Temporary redirect | Used in logins or redirects |
| 304 Not Modified | Resource hasn’t changed | Browser uses cached version |

---

## 4xx — Client Error Codes

| Code | Meaning | Example |
|------|----------|----------|
| 400 Bad Request | Invalid syntax or data | JSON body missing fields |
| 401 Unauthorized | No valid credentials | Missing token or login |
| 403 Forbidden | Access denied | Trying to delete admin data |
| 404 Not Found | Resource doesn’t exist | Wrong URL (e.g. `/users/999`) |
| 409 Conflict | Conflicting request | Creating a user that already exists |

---

## 5xx — Server Error Codes

| Code | Meaning | Example |
|------|----------|----------|
| 500 Internal Server Error | Server crashed | Bug in backend code |
| 502 Bad Gateway | Proxy error between servers | Gateway timed out |
| 503 Service Unavailable | Server overloaded or down | Maintenance or crash |
| 504 Gateway Timeout | Server took too long to respond | Slow or stuck API |

---



## Why RESTFul APIs?
RESTful just means "built according to REST".  
REST = Representational State Transfer. It’s an architectural style for web APIs defined by a small set of constraints.

Mainly, it means it follows those constraints:
- Resource-oriented URLs (nouns, not verbs):   
    **Good:** GET /user/42.  
    **Not RESTful-ish:** POST /getUserById.  

- Method semantics:  
    GET /users → list users (safe, idempotent).  
    POST /user → create a user (returns 201 Created).  
    GET /user/42 → fetch one.  
    PUT /user/42 → replace.  
    DELETE /user/42 → delete (204 No Content).  

- Use status codes & headers correctly

## Request Library
The requests library is one of the most popular and user-friendly Python modules for making HTTP requests.  
It allows your Python programs to communicate with web servers—sending and receiving data—using standard web protocols like HTTP and HTTPS.  

Key Features:
- Send HTTP requests easily — supports GET, POST, PUT, and DELETE.
- Handle responses effortlessly — access status codes, headers, and content directly.
- Work with JSON data — built-in .json() method for parsing JSON responses.
- Manage authentication, sessions, and headers without extra setup.
- Handle errors and exceptions gracefully with clear syntax.


| Feature             | `curl`                                               | `requests`                                                            |
| ------------------- | ---------------------------------------------------- | --------------------------------------------------------------------- |
| **Type**            | Command-line tool                                    | Python library                                                        |
| **Language**        | Used directly in the terminal (bash, zsh, cmd, etc.) | Used inside Python scripts or programs                                |
| **Installation**    | Usually preinstalled on most systems                 | Needs installation via `pip install requests`                         |
| **Usage Context**   | Quick, manual testing of endpoints                   | Automating and processing requests within code                        |
| **Output Handling** | Prints raw response to the terminal                  | Allows easy manipulation of responses (JSON, text, status code, etc.) |
| **Data Parsing**    | Manual (e.g., pipe to `jq` for JSON)                 | Built-in `.json()` and Python data structures                         |
| **Best For**        | Fast debugging, shell scripting, testing APIs        | Integrating APIs into Python apps, data processing, automation        |

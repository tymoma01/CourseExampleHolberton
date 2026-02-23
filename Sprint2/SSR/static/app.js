// Helpers
const $ = (sel, root = document) => root.querySelector(sel);
const $$ = (sel, root = document) => Array.from(root.querySelectorAll(sel));

function renderItems(container, items) {
  container.innerHTML = "";
  for (const t of items) {
    const li = document.createElement("li");
    li.dataset.id = t.id;
    if (t.done) li.classList.add("done");

    const chk = document.createElement("input");
    chk.type = "checkbox";
    chk.className = "toggle";
    chk.checked = !!t.done;

    const text = document.createElement("span");
    text.className = "text";
    text.textContent = t.text;

    const del = document.createElement("button");
    del.className = "del";
    del.type = "button";
    del.textContent = "🗑️";
    del.setAttribute("aria-label", "Delete");

    li.append(chk, text, del);
    container.appendChild(li);
  }
}

async function fetchList() {
  const res = await fetch("/api/todos");
  if (!res.ok) throw new Error("Failed to fetch list");
  return res.json();
}

async function addTodo(text) {
  const res = await fetch("/api/todos", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ text })
  });
  if (!res.ok) throw new Error("Failed to add");
  return res.json();
}

async function toggleTodo(id) {
  const res = await fetch(`/api/todos/${id}`, { method: "PATCH" });
  if (!res.ok) throw new Error("Failed to toggle");
  return res.json();
}

async function deleteTodo(id) {
  const res = await fetch(`/api/todos/${id}`, { method: "DELETE" });
  if (!res.ok && res.status !== 204) throw new Error("Failed to delete");
}

document.addEventListener("DOMContentLoaded", () => {
  const list = $("#list");
  const addForm = $("#add-form");
  const addInput = $("#add-form input[name='text']");

  // Optional: keep client fully in sync on load
  // fetchList().then(items => renderItems(list, items)).catch(console.error);

  addForm.addEventListener("submit", async (e) => {
    e.preventDefault();
    const text = addInput.value.trim();
    if (!text) return;

    try {
      const created = await addTodo(text);

      // Append just the newly created item (no GET round-trip)
      const li = document.createElement("li");
      li.dataset.id = created.id;           // id from server
      // created.done is false by default; no 'done' class

      const chk = document.createElement("input");
      chk.type = "checkbox";
      chk.className = "toggle";
      chk.checked = !!created.done;

      const span = document.createElement("span");
      span.className = "text";
      span.textContent = created.text;

      const del = document.createElement("button");
      del.className = "del";
      del.type = "button";
      del.textContent = "🗑️";
      del.setAttribute("aria-label", "Delete");

      li.append(chk, span, del);
      list.appendChild(li);

      addInput.value = "";
      addInput.focus();
    } catch (err) {
      console.error(err);
    }
  });

  
  // Toggle + Delete via event delegation
  list.addEventListener("click", async (e) => {
    const li = e.target.closest("li[data-id]");
    if (!li) return;
    const id = Number(li.dataset.id);

    if (e.target.matches(".toggle")) {
      try {
        const updated = await toggleTodo(id);
        li.classList.toggle("done", !!updated.done);
      } catch (err) {
        console.error(err);
      }
    }

    if (e.target.matches(".del")) {
      try {
        await deleteTodo(id);
        li.remove();
      } catch (err) {
        console.error(err);
      }
    }
  });
});

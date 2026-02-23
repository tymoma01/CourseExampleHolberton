# Overwrite (or create) the file
with open("notes.txt", "w", encoding="utf-8") as f:
    n = f.write("Hello\n")   # returns number of characters written

print(n)

# Append at the end (or create if missing)
with open("notes.txt", "a", encoding="utf-8") as f:
    m = f.write("World\n")   # adds after existing content

print(m)
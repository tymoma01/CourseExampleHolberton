import pandas as pd

# Python data structure
people = [
    {"name": "John", "age": 28, "city": "New York"},
    {"name": "Alice", "age": 24, "city": "Los Angeles"},
    {"name": "Bob", "age": 22, "city": "Chicago"},
]

# Serialize: save to Excel
df = pd.DataFrame(people)
df.to_excel("people.xlsx", index=False)   # index=False avoids writing row numbers

print("Data serialized and saved to people.xlsx")

# Deserialize: load back from Excel
loaded_df = pd.read_excel("people.xlsx")

print("\nDeserialized DataFrame:")
print(loaded_df)


# Convert back to Python dicts (like JSON-style list of dicts)
records = loaded_df.to_dict(orient="records")
print("\nAs Python list of dicts:")
print(records)

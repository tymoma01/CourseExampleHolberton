import csv, json

rows = []
with open("people.csv", newline="\n", encoding="utf-8") as f:
    for row in csv.DictReader(f):
        rows.append(row)


with open("people.json", "w", encoding="utf-8") as f:
    json.dump(rows, f, ensure_ascii=False, indent=2)


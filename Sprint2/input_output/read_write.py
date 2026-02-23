# Read whole file
def demo_read_all(path):
    with open(path, "r", encoding="utf-8") as f:
        text = f.read()
    print(text)               # file is auto-closed after the with-block









# Read line by line
def demo_read_lines(path):
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            print(line.rstrip())  # avoids double newlines

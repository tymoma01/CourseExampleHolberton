with open("story.txt", "r", encoding="utf-8") as f:
    
    first_5 = f.read(5)
    print(first_5)

    pos = f.tell()
    print(pos)

    f.seek(0)

    again = f.read(10)
    print(again)

with open("that.txt", mode = 'w+') as file:
    file.write("New shit")
    content = file.read()
    print(content)

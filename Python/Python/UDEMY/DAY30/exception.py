try:
    file = open("file.txt")
    dti = {"key" : 1}
    print (dti["fjlksdjf"])
except FileNotFoundError:
    file = open("file.txt", "w")
except IndexError:
    print("key was not found")
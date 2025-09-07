string="Hello,World!!"
for i in range(len(string)):
    if((ord(string[i])>=33 and ord(string[i])<=47)or(ord(string[i])>=58 and ord(string[i])<=64)):
        new_string=string.replace(string[i],'')
print(new_string)
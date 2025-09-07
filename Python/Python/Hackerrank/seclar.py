if __name__ == '__main__':
    s = input()
    lower=0
    uper=0
    alpha=0
    alnum=0
    digits=0
    for i in range(len(s)):
        if(s[i].islower):
            lower=1
            break
    for i in range(len(s)):
        if(s[i].isupper):
            upper=1
            break
    for i in range(len(s)):
        if(s[i].isalnum):
            alnum=1
            break
    for i in range(len(s)):
        if(s[i].isalpha):
            alpha=1
            break
    for i in range(len(s)):
        if(s[i].isdigit):
            digits=1
            break
    if(alnum==1):
        print("True")
    else:
        print("false")
    if(alpha==1):
        print("True")
    else:
        print("false")
    if(digits==1):
        print("True")
    else:
        print("false")
    if(lower==1):
        print("True")
    else:
        print("false")
    if(upper==1):
        print("True")
    else:
        print("false")
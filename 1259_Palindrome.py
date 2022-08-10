s=input()
while(s[0]!='0'):
    stopped=False
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            stopped=True
            break

    print("yes" if not stopped else "no")
    s=input()

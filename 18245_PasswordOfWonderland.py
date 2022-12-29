cnt = 2
while True:
    s = input()

    if s == "Was it a cat I saw?":
        break
    
    for i in range(0, len(s), cnt):
        print(s[i], end="")

    print()
    cnt+=1

    


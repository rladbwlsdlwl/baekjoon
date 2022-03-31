from collections import defaultdict

for _ in range(int(input())):
    cmd=[]
    phone=defaultdict(bool)
    for i in range(int(input())):
        s=input()
        cmd.append(s)
        phone[s]=True

    stopped=False
    for s in cmd:
       for i in range(len(s)-1):
            if phone[s[0:i+1]]:
               stopped=True
               break
       if stopped:
            break
        

    if stopped:
        print("NO")
    else:
        print("YES")
    

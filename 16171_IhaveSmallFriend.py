s=input()
k=input()

sList=""
for c in s:
    if not ord('0')<=ord(c)<=ord('9'):
        sList+=c

print(1 if k in sList else 0)

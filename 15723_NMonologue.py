graph = [[] for _ in range(26)]

def dfs(s, e):
    if s==e:
        return True
    
    for child in graph[s]:
        if dfs(child, e):
            return True

    return False    

for _ in range(int(input())):
    s = list(input().split(" "))
    graph[ord(s[0])-ord('a')].append(ord(s[2])-ord('a'))

for _ in range(int(input())):
    s = list(input().split(" "))
    if dfs(ord(s[0])-ord('a'), ord(s[2])-ord('a')):
        print("T")
    else:
        print("F")

guitar = []


for _ in range(int(input())):
    guitar.append(input())


guitar.sort(key = lambda x: (len(x), sum([int(n) for n in x if n >= '0' and n <= '9']), x))

print(*guitar, sep='\n')

table={
    'black': 0, # 10^0 이라는뜻
    'brown': 1,
    'red': 2,
    'orange': 3,
    'yellow': 4,
    'green': 5,
    'blue': 6,
    'violet': 7,
    'grey': 8,
    'white': 9
}

a,b,c=input(),input(),input()
print(int(str(table[a])+str(table[b]))*10**table[c])

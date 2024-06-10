table = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0.0,
}

grade, total = 0, 0
for _ in range(20):
    subj, g, s = input().split()
    
    if s == 'P': continue

    g = int(g.split(".")[0])
    grade += g * table[s]
    total += g

print(grade / total)

N, M =map(int, input().split())
dna = list(input() for _ in range(N))

ans, cnt = "", 0
for i in range(M):
    table = {'A': 0, 'C': 0, 'G': 0, 'T': 0} # ascd
    for j in range(N):
        table[dna[j][i]] += 1
    
    tmpKey, tmpVal = '', 0
    for key in table:
        if tmpVal < table[key]:
            tmpKey, tmpVal = key, table[key]

    ans += tmpKey
    cnt += N - tmpVal

print(ans)
print(cnt)

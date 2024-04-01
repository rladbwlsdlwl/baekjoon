s = input()

# 작은 문자 찾기
def findSmall(s):
	start = s[0]

	for c in s:
		start = c if ord(start) > ord(c) else start

	return start
# 작은 문자 인덱스 찾기 (리스트 반환)
def findSmallList(s, c):
	return [i for i, char in enumerate(s) if c == char]


def dfs(s, end): # string, cutting count
	if end == 0:
		return s[::-1]

	tmps = s[: len(s) - end]
	tmp = []
	for i in findSmallList(tmps, findSmall(tmps)):
		tmp.append(s[:i+1][::-1] + dfs(s[i+1:], end - 1))

	return sorted(tmp)[0]

print(dfs(s, 2))
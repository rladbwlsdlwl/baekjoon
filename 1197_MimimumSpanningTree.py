import heapq
import sys
input = sys.stdin.readline


# MST - kruskal
# union find
# min heap

V, E = map(int, input().split())
graph = []

for _ in range(E):
	node1, node2, cost = map(int, input().split())
	heapq.heappush(graph, (cost, node1, node2))


# parent node is parent
# other child node is parent (no child)
# ex) 5(5) <- 2(5) <- 1(2)

def findUF(node):
	if uf[node] == node:
		return node
	return findUF(uf[node])

def mergeUF(parent1, parent2):
	if parent1 < parent2: # 작은쪽이 부모노드 (TL)
		uf[parent2] = parent1
	else:
		uf[parent1] = parent2

# init ufind
uf = [i for i in range(V + 1)]
ans = 0
while(V - 1):
	w, n1, n2 = heapq.heappop(graph)

	p1, p2 = findUF(n1), findUF(n2)

	if p1 != p2:
		mergeUF(p1, p2)
		V -= 1
		ans += w

print(ans)
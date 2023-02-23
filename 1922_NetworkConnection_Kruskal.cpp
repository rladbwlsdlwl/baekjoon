#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

struct Node {
	int w, node1, node2;

	Node() : Node(0, 0, 0) {}
	Node(int w, int node1, int node2) : w(w), node1(node1), node2(node2) {}
	
	// descending sort 
	bool operator <(const Node& a) {
		return w < a.w;
	}
};


int uf[1001];
Node graph[100000];

void init_uf(int N) {
	for (int i = 0; i < N; i++)
		uf[i] = i;
}

int find_uf(int p) {
	if(uf[p] != p)
		return find_uf(uf[p]);

	return p;
}

// use KRUSKAL algorithm
int MST(int N, int M) {
	sort(graph, graph + M);

	init_uf(1001);

	int node = 0, cost = 0;
	for (int i = 0; i < M && node < N - 1; i++) {
		int W = graph[i].w, N1 = graph[i].node1, N2 = graph[i].node2;

		if (find_uf(N1) != find_uf(N2)) {
			uf[find_uf(N1)] = find_uf(N2);

			node++;
			cost += W;
		}
	}


	return cost;
}


int main() {
	int N, M;

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int node1, node2, w;
		cin >> node1 >> node2 >> w;

		graph[i] = Node(w, node1, node2);
	}
	

	cout << MST(N, M) << "\n";

	return 0;
}

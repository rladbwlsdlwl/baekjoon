#include<iostream>
#include<vector>

#define inf 999999999
using namespace std;

struct node {
	int s;
	int e;
	int w;
	node(int S, int E, int W) {
		s = S;
		e = E;
		w = W;
	}
};

int main() {
	int N, M, A, B, C;
	cin >> N >> M;

	vector<node>graph;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph.push_back(node(A, B, C));
	}

	long long dis[501];
	fill_n(dis, 501, inf);

	dis[1] = 0;

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			int start = graph[j].s;
			int end = graph[j].e;
			int weight = graph[j].w;
			if (dis[start]!=inf && dis[start] + weight < dis[end])
				dis[end] = dis[start] + weight;
		}
	}
	
	bool stopped = false;
	for (int i = 0; i < M; i++) {
		int start = graph[i].s;
		int end = graph[i].e;
		int weight = graph[i].w;
		if (dis[start] != inf && dis[start] + weight < dis[end]){
			stopped = true;
			break;
		}
	}

	if (stopped)
		cout << "-1\n";
	else {
		for (int i = 2; i <= N; i++) {
			if (dis[i] != inf)
				cout << dis[i] << "\n";
			else
				cout << "-1\n";
		}
	}
	
	return 0;
}

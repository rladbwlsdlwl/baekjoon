#include<iostream>
#include<vector>
#include<queue>

#define MAX 1001


using namespace std;

vector<int>graph[MAX];
bool visited[MAX]; // 방문유무
bool colored[MAX]; // 노드의 색 확인

bool dfs(int parent, bool color) {
	visited[parent] = true;
	colored[parent] = color;

	bool stopped = false;
	for (int i = 0; i < graph[parent].size() && !stopped; i++) {
		int child = graph[parent][i];

		if (!visited[child])
			stopped = dfs(child, !color);
		else {
			if (colored[parent] == colored[child])
				stopped = true;
		}
	}

	return stopped;
}
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		int node1, node2;
		while (m--) {
			cin >> node1 >> node2;

			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		fill_n(visited, MAX, false);
		fill_n(colored, MAX, false);

		if (dfs(node1, true))
			cout << "impossible\n";
		else
			cout << "possible\n";

		for (int i = 1; i <= n; i++)
			graph[i].clear();
	}
}

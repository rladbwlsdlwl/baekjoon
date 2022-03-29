#include<iostream>
#include<queue> 
#include<vector>
#include<algorithm> 

#define MAX 1001

using namespace std;

vector<int>graph[MAX];
bool visited[MAX];

void dfs(int node) {
	cout << node << " ";
	visited[node] = true;
	sort(graph[node].begin(), graph[node].end());

	int child;
	for (int i = 0; i < graph[node].size(); i++) {
		child = graph[node][i];
		if (!visited[child])
			dfs(child);
	}
}

void bfs(int node) {
	queue<int>q;
	q.push(node);
	visited[node] = true;

	int p, child;
	while (!q.empty()) {
		p = q.front();
		q.pop();

		cout << p << " ";
		for (int i = 0; i < graph[p].size(); i++) {
			child = graph[p][i];
			if (!visited[child]) {
				q.push(child);
				visited[child] = true;
			}
		}
	}
}
int main() {
	int n, m, node;
	cin >> n >> m >> node;

	int node1, node2;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	
	fill_n(visited, MAX, false);
	dfs(node);
	cout << "\n";

	fill_n(visited, MAX, false);
	bfs(node);
	cout << "\n";

	return 0;
}

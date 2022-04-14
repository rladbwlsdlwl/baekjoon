#include<iostream>
#include<vector>
#define MAX 101

using namespace std;

vector<int>graph[MAX];
bool visited[MAX] = { false, };

int dfs(int parent) {
	visited[parent] = true;

	int cnt = 0;
	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child])
			cnt += 1 + dfs(child);
	}

	return cnt;
}

int main() {
	int n;
	cin >> n >> n;

	int node1, node2;
	for (int i = 0; i < n; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	cout << dfs(1) << "\n";

	return 0;
}

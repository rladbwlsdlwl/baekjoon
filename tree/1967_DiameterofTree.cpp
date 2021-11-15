#include<iostream>
#include<vector>
#define MAX 10001

using namespace std;

vector<pair<int, int>>graph[MAX]; // (vertex, weight)
bool visited[MAX];

int maxLen = 0;
int v;
void dfs(int vertex, int length) {
	visited[vertex] = true;

	if (maxLen < length) {
		maxLen = length;
		v = vertex;
	}

	for (int i = 0; i < graph[vertex].size(); i++) {
		pair<int, int> next = graph[vertex][i];
		if (!visited[next.first])
			dfs(next.first, length + next.second);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		graph[v1].push_back(make_pair(v2, w));
		graph[v2].push_back(make_pair(v1, w));
	}

	fill_n(visited, MAX, false);
	dfs(1, 0); // 가장 먼거리를 찾는다

	fill_n(visited, MAX, false);
	dfs(v, 0); // 가장 먼 거리의 정점에서의 가장 먼 거리를 찾는다 (diameter)

	cout << maxLen;

	return 0;
}

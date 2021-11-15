#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

vector<pair<int, int>> graph[MAX];
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

	for (int i = 0; i < n; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graph[v1].push_back(make_pair(v2, w));

		while (true) {
			cin >> v2;
			if (v2 == -1)
				break;
			cin >> w;
			graph[v1].push_back(make_pair(v2, w));
		}
	}

	fill_n(visited, MAX, false);
	dfs(1, 0);

	fill_n(visited, MAX, false);
	dfs(v, 0);

	cout<<maxLen<<"\n";

	return 0;
}


#include<iostream>
#include<vector>
#define MAX 100001

using namespace std;

vector<int>node[MAX];
int parent[MAX];
bool visited[MAX];

void dfs(int p) {
	visited[p] = true;
	for (int i = 0; i < node[p].size(); i++) {
		int next = node[p][i];
		if (!visited[next]) {
			parent[next] = p;
			dfs(next);
		}
	}
}

int main() {
	int n;
	cin >> n;

	fill_n(visited, MAX, false);

	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i]<<"\n";

	return 0;
}

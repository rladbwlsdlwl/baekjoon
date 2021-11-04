#include<iostream>
#include<vector>
#define MAX 501

using namespace std;

vector<int>graph[MAX];
bool visited1[MAX];
bool visited2[MAX];

int dfs_v(int n) {
	int vertex = 1;
	visited1[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		if (!visited1[next])
			vertex += dfs_v(next);
	}

	return vertex;
}

int dfs_e(int n) {
	int edge = graph[n].size();
	visited2[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		if (!visited2[next])
			edge += dfs_e(next);
	}

	return edge;
}

int main() {
	int n, m;
	int p = 1;
	while (true) {
		
		for (int i = 0; i < MAX; i++)
			graph[i].clear();

		fill_n(visited1, MAX, false);
		fill_n(visited2, MAX, false);

		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < m; i++) {
			int n1, n2;
			cin >> n1 >> n2;

			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited1[i])
				continue;
			int v = dfs_v(i);
			int e = dfs_e(i);

			if (v - 1 == e/2)
				cnt++;
		}

		cout << "Case " << p++;
		if (cnt > 1)
			cout << ": A forest of " << cnt << " trees.\n";
		else if (cnt == 1)
			cout << ": There is one tree.\n";
		else
			cout << ": No trees.\n";
	}

	return 0;
}

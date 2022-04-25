#include<iostream>
#include<vector>
#define MAX 50

using namespace std;

vector<int>graph[MAX + 1];
bool visited[MAX + 1];

void dfs(int parent) {
	visited[parent] = true;
	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child])
			dfs(child);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int t;
	cin >> t;

	vector<int>truth(t);
	for (int i = 0; i < t; i++)
		cin >> truth[i];

	vector<vector<int>>party;
	for (int i = 0; i < m; i++) {
		vector<int>tmp;
		
		int n_, node1, node2;
		cin >> n_;
		cin >> node1;
		
		tmp.push_back(node1);
		for (int i = 1; i < n_; i++) {
			cin >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);

			tmp.push_back(node2);
		}

		party.push_back(tmp);
	}

	if (t) {
		fill_n(visited, MAX + 1, false);
		for (int i = 0; i < t; i++)
			dfs(truth[i]);

		int ans = 0;
		for (int i = 0; i < m; i++) {
			bool stopped = false;
			for (int j = 0; j < party[i].size(); j++) {
				if (visited[party[i][j]]) {
					stopped = true;
					break;
				}
			}

			if (!stopped)
				ans++;
		}

		cout << ans << "\n";
	}
	else
		cout << m << "\n";


	return 0;
}


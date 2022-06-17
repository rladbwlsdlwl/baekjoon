#include<iostream>
#include<vector>
#define MAX 100001

using namespace std;

vector<int>graph[MAX];
vector<bool>visited(MAX, false);
vector<int>dp(MAX, 0);

int dfs(int parent) {
	visited[parent] = true;

	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child])
			dp[parent] += dfs(child);
	}
	dp[parent] += 1; // add myself
	
	return dp[parent];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	while (--N) {
		int node1, node2;
		cin >> node1 >> node2;
		
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	dfs(R);

	while (Q--) {
		int n;
		cin >> n;

		cout << dp[n] << "\n";
	}

	return 0;
}

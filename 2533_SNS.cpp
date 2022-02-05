#include<iostream>
#include<vector>
#include<algorithm> // use min
#define MAX 1000001

using namespace std;

vector<int>graph[MAX];
int dp[MAX][2]; // 0 -> not early adaptor 1 -> early adaptor
bool visited[MAX];

void dfs(int parent) {
	visited[parent] = true;
	dp[parent][1] = 1; // parent is Early-Adaptor
	dp[parent][0] = 0; // Not Early-Adaptor

	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child]) {
			dfs(child);
			dp[parent][1] += min(dp[child][0], dp[child][1]); // if parent is Early-Adaptor, child will be early or Not early
			dp[parent][0] += dp[child][1]; 
		}
	}
}

int main() {
	int N;
	cin >> N;

	while (--N) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill_n(visited, MAX, false);

	dfs(1);

	cout << (dp[1][0] > dp[1][1] ? dp[1][1] : dp[1][0]) << "\n";

	return 0;
}

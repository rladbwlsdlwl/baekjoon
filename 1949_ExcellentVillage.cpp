#include<iostream>
#include<vector>
#define MAX 10001

using namespace std;

vector<int>graph[MAX];
bool visited[MAX];

int person[MAX];
int dp[MAX][2]; // col_0 -> not selected, col_1 -> selected

void dfs(int parent) {
	visited[parent] = true;

	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child]) {
			dfs(child);
			dp[parent][0] += max(dp[child][0], dp[child][1]);
			dp[parent][1] += dp[child][0];
		}
	}

	dp[parent][1] += person[parent];
}


int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		cin >> person[i];
	
	while (--N) {
		int node1, node2;
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	fill_n(visited, MAX, false);
	dfs(1);

	cout << max(dp[1][0], dp[1][1]);

	return 0;

}

#include<iostream>
#include<vector>
#define MAX 100001

using namespace std;

vector<int>graph[MAX];
bool visited[MAX];
int dp[MAX];

void dfs(int parent) {
	int cnt = 1;
	visited[parent] = true;

	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (!visited[child]) {
			dfs(child);
			cnt += dp[child];
		}
	}

	dp[parent] = cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	fill_n(visited, MAX, false);

	
	dfs(R);

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << dp[q] << "\n";
	}

	
	return 0;
}

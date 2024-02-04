#include<iostream>
#include<vector>
#define MAX 10001

using namespace std;

vector<int>graph[MAX];
bool visited[MAX];

int dfs(int parent) {
	int cnt = 1;
	visited[parent] = true;

	for (int i = 0; i<graph[parent].size();i++){
		int child = graph[parent][i];
		if(!visited[child])
			cnt += dfs(child);
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	while (M--) {
		int node1, node2;
		cin >> node1 >> node2;

		graph[node2].push_back(node1);
	}

	int mxCnt = 0;
	vector<int>ans(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		fill_n(visited, MAX, false);
		ans[i] = dfs(i);
		mxCnt = max(mxCnt, ans[i]);
	}


	for (int i = 1; i <= N; i++) {
		if (mxCnt == ans[i])
			cout << i << " ";
	}

	return 0;
}
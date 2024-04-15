#include<iostream>
#include<vector>
#include<queue>

#define MAX 1000
#define INF 10000000

using namespace std;

// Shortest path
// Floyd Warshall

int dp[MAX][MAX];
int main() {
	int N, M, X;

	cin >> N >> M >> X;

	// init
	for (int i = 0; i < N; i++) {
		fill_n(dp[i], N, INF);
		dp[i][i] = 0;
	}



	for (int i = 0; i < M; i++) {
		int node1, node2, cost; 
		cin >> node1 >> node2 >> cost;

		dp[node1 -1 ][node2 - 1] = cost;
	}


	for (int i = 0; i < N; i++) { // i = 경유노드
		for (int j = 0; j < N; j++) { // j = 경유노드를 제외한 노드 (출발노드)
			for (int k = 0; k < N; k++) // k = 도착노드
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i][X-1] + dp[X-1][i]);

	cout << ans << "\n";

	return 0;

}

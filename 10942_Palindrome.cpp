#include<iostream>
#define MAX 2001
using namespace std;

int cmd[MAX];
int dp[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> cmd[i];

	for (int i = 0; i < MAX; i++)
		fill_n(dp[i], MAX, 1);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= i; j--) {
			if (cmd[i] == cmd[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << (dp[a - 1][b - 1] == 1 ? "1" : "0") << "\n";
	}

	return 0;
}

#include<iostream>
#include<vector>
#define MAX 1000
using namespace std;

int ans = 0;
int n, m;
string road[MAX];
bool escape;
void solution(vector<vector<int>>dp, int start_c) {
	ans = 0;
	escape = false;

	for (int j = start_c; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (road[i][j] == '#')
				continue;

			if (i - 1 >= 0 && j - 1 >= 0 && dp[i-1][j-1] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (j - 1 >= 0 && dp[i][j - 1] != -1)
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (i + 1 < n && j - 1 >= 0 && dp[i + 1][j - 1] != -1)
				dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);

			if (road[i][j] == 'C' && dp[i][j] != -1)
				dp[i][j]++;
			else if (road[i][j] == 'O' && dp[i][j] != -1) {
				escape = true;
				ans = max(ans, dp[i][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	//input
	for (int i = 0; i < n; i++)
		cin >> road[i];

	//find rabbit && init dp
	int start_r = 0, start_c = 0;
	vector<vector<int>>dp(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (road[i][j] == 'R') {
				start_r = i;
				start_c = j;
				dp[i][j] = 0;
				break;
			}
		}
	}

	solution(dp, start_c);
	cout << (escape ? ans : -1) << "\n";
	return 0;
}


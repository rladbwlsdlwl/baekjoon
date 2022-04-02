#include<iostream>
#include<vector>
#define MAX 10000
using namespace std;

vector<int>work[MAX];
int main() {
	int n;
	cin >> n;
	
	int w, day;
	for (int i = 0; i < n; i++) {
		cin >> w >> day;
		work[i].push_back(w);
		work[i].push_back(day);

		for (int j = 0; j < work[i][1]; j++) {
			cin >> w;
			work[i].push_back(w);
		}
	}

	int time = 0;
	vector<int>dp(n, 0);

	for (int i = 0; i < n; i++) {
		dp[i] = work[i][0];
		for (int j = 2; j < 2+work[i][1]; j++)
			dp[i] = max(dp[i], dp[work[i][j]-1] + work[i][0]);
		time = max(time, dp[i]);
	}

	cout << time << "\n";
	return 0;

}

#include<iostream>
#define MAX 1000

using namespace std;

const int INF = 9999;
int dp[MAX];
int jump[MAX];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> jump[i];


	fill_n(dp, MAX, INF);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] == INF || dp[N - 1] != INF)
			break;
		while (jump[i]) {
			if (i + jump[i] < N){
				if (dp[i + jump[i]] <= dp[i] + 1)
					break;
				dp[i + jump[i]] = dp[i] + 1;
			}
			
			jump[i]--;
		}
	}


	cout << (dp[N - 1] == INF ? -1 : dp[N - 1]) << "\n";

	return 0;
}

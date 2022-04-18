#include<iostream>
#define MAX 10000

using namespace std;

int card[MAX];
int dp[MAX];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> card[i];

	for (int i = 0; i < N; i++) {
		dp[i] = card[i];
		for (int j = 0; j <= i/2; j++) 
			dp[i] = max(dp[i], dp[j] + dp[i - 1 - j]);
	}


	cout << dp[N - 1] << "\n";
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int A[1000];
int dp[1000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	
	fill_n(dp, 1000, 1);
	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (A[j] < A[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int mLen = 0;
	for (int i = 0; i < N; i++)
		mLen = max(mLen, dp[i]);

	cout << mLen << "\n";
	return 0;
}

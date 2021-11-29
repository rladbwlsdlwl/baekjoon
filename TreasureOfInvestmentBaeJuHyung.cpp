#include<iostream>
#include<algorithm>
#define MAX 11

using namespace std;
int main() {
	int H, Y;
	cin >> H >> Y;

	int dp[MAX];
	dp[0] = H;

	for (int i = 1; i < Y+1; i++) {
		dp[i] = (int)(dp[i - 1] * 1.05);
		if (i >= 3)
			dp[i] = max(dp[i], (int)(dp[i - 3] * 1.2));
		if (i >= 5)
			dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
	}

	cout << dp[Y] << "\n";

	return 0;
}

#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[] = { 64,32,16,8,4,2,1 };
	int cnt = 0;

	for (int i = 0; i < 7; i++) {
		if (n == 0)
			break;
		if (n - dp[i] >= 0) {
			n -= dp[i];
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}

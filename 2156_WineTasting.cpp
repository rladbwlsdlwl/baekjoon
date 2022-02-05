#include<iostream>
#include<algorithm> // use max
#define MAX 10001

using namespace std;

int dp[MAX]; // 각 인덱스마다 마시는 걸로 가정
int wine[MAX];

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}

void sol(int n) {
	if (n ==1) {
		cout << wine[1] << "\n";
		return;
	}
	else if (n == 2) {
		cout << wine[1] + wine[2] << "\n";
		return;
	}

	wine[0] = 0;
	dp[0] = 0; dp[1] = wine[1]; dp[2] = wine[1] + wine[2]; dp[3] = max(wine[3] + wine[2], wine[3] + dp[1]);

	for (int i = 4; i <= n; i++)
		dp[i] = max(wine[i] + wine[i - 1] + dp[i - 3], wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 4]); // 연속 , 자기자신, 두번 건너뛰고 마시기
	
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = (dp[i] > dp[mx] ? i : mx);

	cout << dp[mx] << "\n";
}

// 100 400 2 1 4 200 -> 100 400 4 200 으로 두번 건너뛰고 와인을 마셔서 704만큼 마실 수 있다 (dp[i-4]+arr[i]+arr[i-1])
int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	sol(n);

	return 0;
}

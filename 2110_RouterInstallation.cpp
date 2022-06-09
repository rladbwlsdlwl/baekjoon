#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	vector<int>home(N);
	for (int i = 0; i < N; i++)
		cin >> home[i];

	sort(home.begin(), home.end());


	int ans = 0;
	int left = 1, right = home[N - 1] - home[0]; // left = 집 간의 최소 거리, right = 집 간의 최대거리
	while (left <= right) { // 집의 위치에 대한 이분탐색 진행
		int mid = (left + right) / 2;

		int cnt = 1;
		int prev = home[0];
		for (int i = 1; i < N; i++) {
			if (home[i] - prev >= mid) {
				cnt++;
				prev = home[i];
			}
		}

		if (cnt >= C) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans << "\n";

	return 0;
}

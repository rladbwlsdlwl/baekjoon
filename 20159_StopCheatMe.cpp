#include<iostream>

using namespace std;

int card[10'0000];

int prefix_even[10'0000];
int prefix_odd[10'0000];

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> card[i];


	prefix_even[0] = card[0], prefix_even[1] = card[1];
	for (int i = 2; i < N; i += 2) {
		prefix_even[i] = prefix_even[i - 2] + card[i];
		prefix_even[i + 1] = prefix_even[i - 1] + card[i];
	}

	prefix_odd[1] = card[1], prefix_odd[2] = card[2];
	for (int i = 3; i < N - 1; i += 2) {
		prefix_odd[i] = prefix_odd[i - 2] + card[i];
		prefix_odd[i + 1] = prefix_odd[i - 1] + card[i];
	}

	if (N == 2) {
		cout << max(card[0], card[1]) << "\n";

		return 0;
	}



	// 밑장빼기를 안했을 경우
	int ans = prefix_even[N-2];


	// 밑장빼기를 했을경우 가능한 최댓값을 찾음
	//i가 1일경우
	ans = max(ans, prefix_odd[N - 3] + max(card[0], card[N - 1]));

	// 그 외의 경우
	for (int i = 3; i < N - 1; i += 2) {
		int money1 = prefix_odd[N - 3] - prefix_odd[i - 2];
		int money2 = prefix_even[i - 3] + max(card[i - 1], card[N - 1]);

		ans = max(ans, money1 + money2);
	}

	// 마지막 턴에 카드를 변경
	ans = max(ans, prefix_even[N - 4] + max(card[N - 1], card[N - 2]));

	cout << ans << "\n";

	return 0;
}

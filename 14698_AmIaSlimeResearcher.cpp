#include<iostream>
#include<queue> // using priority_queue

const int MOD = 1000'000'007;

using namespace std;

struct compare { // min heap
	bool operator()(const long long a, const long long b) {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;

	long long w, ans;
	priority_queue<long long, vector<long long>, compare>q;
	while (T--) {
		ans = 1;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> w;

			q.push(w);
		}

		while (!q.empty()) {
			long long a = q.top();
			q.pop();

			if (q.empty())
				break;

			long long b = q.top();
			q.pop();

			q.push(a * b); // mod 하면 곱하는 값이 달라짐
			ans = (ans * (a % MOD * b % MOD) % MOD) % MOD;// 출력하고자 하는 값만 mod
		}

		cout << ans << "\n";
	}

	return 0;
}

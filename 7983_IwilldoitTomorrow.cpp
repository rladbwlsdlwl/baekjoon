#include<iostream>
#include<queue> // max heap

using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
	}
};

int main() {
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare>hq;

	int n;
	cin >> n;

	while (n--) {
		pair<int, int>tmp;
		cin >> tmp.first >> tmp.second;
		hq.push(tmp);
	}

	int ans = 1000000000;
	while (!hq.empty()) {
		pair<int,int> p = hq.top();
		if (p.second <= ans)
			ans = p.second - p.first;
		else
			ans -= p.first;

		hq.pop();
	}

	cout << ans << "\n";

	return 0;
}

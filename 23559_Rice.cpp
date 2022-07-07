#include<iostream>
#include<queue> // using priority_queue
#include<vector>

using namespace std;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first - a.second < b.first - b.second; // distance max heap
	}
};


int main() {
	int N, X;
	cin >> N >> X;

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>price; // 손해를 적게보도록 정렬 

	while (N--) {
		int a, b;
		cin >> a >> b;

		price.push({ a,b });
	}


	int ans = 0, cost = X;
	while (!price.empty()) {
		pair<int, int>top = price.top();
		price.pop();

		if ((cost - 5000)/1000 >= (int)price.size()) {
			if (top.first > top.second) {
				ans += top.first;
				cost -= 5000;
			}
			else {
				ans += top.second;
				cost -= 1000;
			}
		}
		else {
			ans += top.second;
			cost -= 1000;
		}
	}

	cout << ans << "\n";


	return 0;
}

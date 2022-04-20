#include<iostream>
#include<queue>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int>hq; //max heap

	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;

		if (n)
			hq.push(-1 * n);
		else {
			if (hq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << hq.top() * -1 << "\n";
			hq.pop();
		}
	}
}

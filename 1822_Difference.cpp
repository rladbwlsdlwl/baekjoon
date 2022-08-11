#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int>aSet(n, 0);
	vector<int>bSet(m, 0);

	for (int i = 0; i < n; i++)
		cin >> aSet[i];
	for (int i = 0; i < m; i++)
		cin >> bSet[i];

	sort(aSet.begin(), aSet.end(), [](int& a, int& b) {
		return a < b;
	});
	sort(bSet.begin(), bSet.end(), [](int& a, int& b) {
		return a < b;
	});

	int i = 0;
	int ans = n;
	vector<bool>pureA(n, true);
	for (int j = 0; j < m; j++) {
		int b = bSet[j];
		while (i < n-1 && aSet[i] < b)
			i++;

		if (aSet[i] == b) {
			pureA[i] = false;
			ans--;
		}
	}

	if (ans) {
		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			if (pureA[i])
				cout << aSet[i] << " ";
		}
	}
	else
		cout << "0\n";

	return 0;
}

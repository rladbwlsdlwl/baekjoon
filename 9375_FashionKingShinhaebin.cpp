#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vector <pair<string, int>> table;

		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			string a, b;
			cin >> a >> b;

			bool stopped = false;
			for (int k = 0; k < (int)table.size(); k++) {
				if (table[k].first == b) {
					table[k].second++;
					stopped = true;
					break;
				}
			}

			if (stopped == false) {
				table.push_back(make_pair(b,1));
			}
		}

		int ans = 1;
		for (int j = 0; j < (int)table.size(); j++)
			ans *= table[j].second + 1;

		
		cout << ans-1 << "\n";
	}


	return 0;
}

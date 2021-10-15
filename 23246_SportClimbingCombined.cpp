#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	vector <vector<int>> table;

	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;

		vector<int> tmp;
		tmp.push_back(x * y * z);
		tmp.push_back(x + y + z);
		tmp.push_back(n);

		table.push_back(tmp);
	}

	sort(table.begin(),table.end());

	for (int i = 0; i < 3; i++)
		cout << table[i][2]<<" ";

	cout << "\n";

	return 0;
}

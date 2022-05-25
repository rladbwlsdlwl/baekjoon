#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>top(N+1);
	for (int i = 1; i <= N; i++)
		cin >> top[i];

	vector<pair<int, int>>stk; // (laser, idx) 
	for (int i = 1; i <= N; i++) {
		while (!stk.empty() && stk.back().first < top[i])
			stk.pop_back();

		if (!stk.empty())
			cout << stk.back().second << " ";
		else
			cout << "0 ";
		stk.push_back({ top[i], i });
	}

	cout << "\n";
	return 0;
}

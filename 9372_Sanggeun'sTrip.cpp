#include<iostream>
#include<vector>

using namespace std;
int main() {
	int t;
	cin >> t;

	while (t--) {
		int N, M, node1, node2;
		cin >> N >> M;
		for (int i = 0; i < M; i++)
			cin >> node1 >> node2;

		cout << N - 1 << "\n";
	}

	return 0;
}


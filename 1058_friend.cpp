#include<iostream>
#include<cmath>
using namespace std;

int rel[50][50];
int frd[50][50];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		for (int j = 0; j < cmd.size(); j++)
			rel[i][j] = (cmd[j] == 'Y' ? 1 : 0);
	}

	// Floyd-Warshall 
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				if (rel[i][j] == 1 || rel[i][k] == 1 && rel[k][j] == 1)
					frd[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < N; j++)
			tmp += frd[i][j];
		ans = max(ans, tmp);
	}

	cout << ans << "\n";
	return 0;
}

#include<iostream>
#define MAX 128

using namespace std;

int N;
int cntW, cntB;
int colored[MAX][MAX];


bool isValid(int r1, int r2, int c1, int c2) {
	bool white = (colored[r1][c1] == 0 ? true : false);
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			if (white && colored[i][j] != 0 || !white && colored[i][j]!=1)
				return false;
		}
	}

	if (white)
		cntW++;
	else
		cntB++;

	return true;
}


void getCountingConfetti(int from_r, int to_r, int from_c, int to_c, int n) {
	if (!isValid(from_r, to_r - n / 2, from_c, to_c - n / 2))
		getCountingConfetti(from_r, to_r - n / 2, from_c, to_c - n / 2, n / 2);
	if (!isValid(from_r, to_r - n / 2, from_c + n / 2, to_c))
		getCountingConfetti(from_r, to_r - n / 2, from_c + n / 2, to_c, n / 2);
	if (!isValid(from_r + n / 2, to_r, from_c, to_c - n / 2))
		getCountingConfetti(from_r + n / 2, to_r, from_c, to_c - n / 2, n / 2);
	if (!isValid(from_r + n / 2, to_r, from_c + n / 2, to_c))
		getCountingConfetti(from_r + n / 2, to_r, from_c + n / 2, to_c, n / 2);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> colored[i][j];
	}

	cntW = 0, cntB = 0;
	if (!isValid(0, N - 1, 0, N - 1))
		getCountingConfetti(0, N - 1, 0, N - 1, N);

	cout << cntW << "\n" << cntB << "\n";

	return 0;
}

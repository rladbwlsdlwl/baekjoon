#include<iostream>

using namespace std;

int size1, size2;
string A, B, AB;

int dp[201][201];

bool dfs(int i, int j, int p) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == size1 && j == size2)
		return dp[i][j] = 1;


	if (i < size1 && AB[p] == A[i])
		dp[i][j] = dfs(i + 1, j, p + 1);
	if (j < size2 && AB[p] == B[j] && dp[i][j] != 1)
		dp[i][j] = dfs(i, j + 1, p + 1);


	return dp[i][j] == -1 ? 0 : dp[i][j];
}

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B >> AB;

		// initialize
		size1 = A.size(), size2 = B.size();

		for (int i = 0; i < 201; i++) {
			for (int j = 0; j < 201; j++)
				fill_n(dp[i], 201, -1);
		}



		cout << "Data set " << i + 1;

		if (dfs(0, 0, 0))
			cout << ": yes\n";
		else
			cout << ": no\n";
	}


	return 0;
}

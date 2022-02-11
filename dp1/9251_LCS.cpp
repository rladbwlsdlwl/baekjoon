#include<iostream>
#include<algorithm>
#define MAX 1000

using namespace std;

int dp[MAX + 1][MAX + 1] = { 0, };
int solution(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	return dp[s1.size()][s2.size()];

}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	cout << solution(s1, s2) << "\n";

	return 0;
}

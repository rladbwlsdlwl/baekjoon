#include<iostream>
#include<vector>
#include<algorithm> //use max
#define MAX 1000
using namespace std;

int get_LCB(vector <int>& A) {
	int asc_dp[MAX]; //ascending seq
	int dec_dp[MAX]; //decsending seq

	fill_n(asc_dp, MAX, 1);
	fill_n(dec_dp, MAX, 1);

	for (int i = 0; i < A.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] > A[j])
				asc_dp[i] = max(asc_dp[i], asc_dp[j] + 1);
		}
	}
	for (int i = A.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < A.size(); j++) {
			if (A[i] > A[j])
				dec_dp[i] = max(dec_dp[i], dec_dp[j] + 1);
		}
	}

	int mLen = 0;
	for (int i = 0; i < A.size(); i++)
		mLen = max(mLen, asc_dp[i] + dec_dp[i] - 1);

	return mLen;
}

int main() {
	int N;
	cin >> N;

	vector<int>A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << get_LCB(A) << "\n";

	return 0;
}

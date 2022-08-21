#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int getCargoTime(vector<int>& crain, vector<int>& box) {
	if (crain.back() < box.back())
		return -1;

	vector<int>time(N, 0);
	int j = N - 1;

	// 범위에 따라 카운팅
	for (int i = M - 1; i >= 0; i--) {
		while (j >= 1 && crain[j - 1] >= box[i])
			j--;

		time[j]++;
	}

	int total = M;

	for (int i = 0; i < N - 1; i++) {
		int mid = (total / (N - i)) + ((total % (N - i)) ? 1 : 0);
		if (time[i] > mid) {
			time[i + 1] = time[i + 1] + time[i] - mid;
			time[i] = mid;
		}

		total -= time[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, time[i]);

	return ans;
}

int main() {
	cin >> N;
	vector<int>crain(N);

	for (int i = 0; i < N; i++)
		cin >> crain[i];

	cin >> M;
	vector<int>box(M);

	for (int i = 0; i < M; i++)
		cin >> box[i];


	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	cout << getCargoTime(crain, box) << "\n";


	return 0; 
}

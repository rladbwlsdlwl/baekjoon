#include<iostream>
#include<queue>

using namespace std;

int subj[200000];
int add[200000];
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> subj[i];
	for (int i = 0; i < M; i++)
		cin >> add[i];


	priority_queue<pair<int, int>>hq; // ascending val, subject score <MAX heap>
	for (int i = 0; i < M; i++) {
		if (subj[i] + add[i] > 100)
			hq.push({ 100 - subj[i], subj[i] });
		else
			hq.push({ add[i], subj[i] });
	}

	for (int i = 0; i < N * 24; i++) {
		pair<int,int> top = hq.top();
		if (top.first == 0)
			break;

		hq.pop();
		if (top.first + top.second > 100) { // 100을 넘게될 경우 우선할 값이 변경되었는지를 체크하기 위해 값을 변경
			hq.push({ 100 - top.second, top.second });
		
			top = hq.top();
			hq.pop();
		}
		// 공부 시작
		hq.push({ (top.first + top.second == 100 ? 0 : top.first),top.second + top.first });
	}

	int ans = 0;
	while (!hq.empty()) {
		ans += hq.top().second;
		hq.pop();
	}

	cout << ans << "\n";
	return 0;
}

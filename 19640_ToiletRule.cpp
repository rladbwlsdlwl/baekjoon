#include<iostream>
#include<queue>
#include<vector>
#define MAX 100000


int N, M, K;
int person[MAX][2];

struct Node {
	int day;
	int hurry;
	int idx;

	Node(int d, int h, int i) {
		day = d;
		hurry = h;
		idx = i;
	}
};

struct compare {
	bool operator()(Node& a, Node& b) {
		if (a.day == b.day) {
			if (a.hurry == b.hurry)
				return a.idx % M > b.idx % M;
			return a.hurry < b.hurry;
		}
		return a.day < b.day;
	}
};

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> person[i][0] >> person[i][1];


	priority_queue<Node, vector<Node>, compare> hq;
	for (int i = 0; i < M; i++) {
		if (i >= N)
			break;
		hq.push(Node(person[i][0], person[i][1], i));
	}

	int ans = 0;
	while (!hq.empty()) {
		Node p = hq.top();
		hq.pop();

		if (p.idx == K)
			break;

		if (p.idx + M < N)
			hq.push(Node(person[p.idx + M][0], person[p.idx + M][1], p.idx + M));

		ans++;
	}

	cout << ans << "\n";
	return 0;
}

#include<iostream>
#include<algorithm> //use max, min
#include<vector>
#define INF_ 0
#define INF 1000000001

using namespace std;

struct SegmentTree {
	vector<int>num;
	vector<int>segmx; // 최댓값을 저장하는 segmentTree
	vector<int>segmn; // 최솟값을 저장하는 segmentTree

	int n = 0;

	SegmentTree(int n_, vector<int>tmp) {
		n = n_;
		segmx.resize(n,0);
		segmn.resize(n,0);
		for (int i = 0; i < tmp.size(); i++)
			num.push_back(tmp[i]);
	}
	
	void initializer(int start,int end,int node) {
		init(start, end, node);
		init_(start, end, node);
	}
	int init(int start, int end, int node) {
		if (start == end) {
			segmx[node] = num[start];
			return segmx[node];
		}
		int mid = (start + end) / 2;
		segmx[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
	
		return segmx[node];
	}

	int init_(int start, int end, int node) {
		if (start == end) {
			segmn[node] = num[start];
			return segmn[node];
		}

		int mid = (start + end) / 2;
		segmn[node] = min(init_(start, mid, node * 2), init_(mid + 1, end, node * 2 + 1));

		return segmn[node];
	}

	int find_max(int start, int end, int s, int e, int node) {
		if (end < s || start > e)
			return INF_;
		if (s <= start && e >= end) 
			return segmx[node];
			
		int mid = (start + end) / 2;
		return max(find_max(start, mid, s, e, node * 2), find_max(mid + 1, end, s, e, node * 2 + 1));
	}

	int find_min(int start, int end, int s, int e, int node) {
		if (s > end || e < start)
			return INF;
		if (s <= start && e >= end)
			return segmn[node];

		int mid = (start + end) / 2;
		return min(find_min(start, mid, s, e, node * 2), find_min(mid + 1, end, s, e, node * 2 + 1));
	}
};


void getMaxMin(vector<int>& cmd, vector<pair<int, int>>& query) {
	SegmentTree* s = new SegmentTree(cmd.size() * 4, cmd);
	s->initializer(0, cmd.size() - 1, 1);
	
	for (int i = 0; i < query.size(); i++)
		cout << s->find_min(0, cmd.size() - 1, query[i].first - 1, query[i].second - 1, 1) << " " << s->find_max(0, cmd.size() - 1, query[i].first - 1, query[i].second - 1, 1) << "\n";
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<int>cmd(N);
	for (int i = 0; i < N; i++)
		cin >> cmd[i];

	vector<pair<int, int>>query(M);
	for (int i = 0; i < M; i++)
		cin >> query[i].first >> query[i].second;

	getMaxMin(cmd, query);

	
	return 0;
}

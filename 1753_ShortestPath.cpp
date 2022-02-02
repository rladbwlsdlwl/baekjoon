#include<iostream>
#include<vector>
#include<queue> // priority_queue (max heap)
#define MAX 20001

const int INF = 9999999; 
using namespace std;


using pii = pair<int, int>; // (weight, end-node)
vector<pii>graph[MAX];
int dp[MAX];

void shortestPath(int k) {
	fill_n(dp, MAX, INF);
	
	priority_queue<pii>heapq; 
	dp[k] = 0;
	heapq.push(make_pair(0, k));
	
	while (!heapq.empty()) {
		int W = -1 * heapq.top().first; // pop it, multiply -1
		int N = heapq.top().second;
		heapq.pop();

		if (dp[N] < W) // multiple edge
			continue;
		for (int i = 0; i < graph[N].size(); i++) {
			int weight = graph[N][i].first;
			int endNode = graph[N][i].second;
			if (dp[endNode] > W+weight) {
				dp[endNode] = W + weight;
				heapq.push(make_pair(-1*dp[endNode], endNode)); // change min heap
			}

		}
	}

}

int main() {
	int V, E;
	cin >> V >> E;

	int k;
	cin >> k;

	while (E--) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back(make_pair(w, e));
	}

	shortestPath(k);

	for (int i = 1; i <= V; i++) {
		if (dp[i] == INF)
			cout << "INF\n";
		else
			cout << dp[i] << "\n";
	}

	return 0;
}


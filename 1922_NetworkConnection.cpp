#include<iostream>
#include<vector>
#include<queue> // priority_queue
#define MAX 1001

using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		// min heap
		if (a.first == b.first)
			return a.second > b.second;

		return a.first > b.first;
	}
};


vector<pair<int, int>> graph[MAX]; // {weight, node]
bool visited[MAX] = { false, };

// use PRIM algorithm
int MST(int N) {
	int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>hq;

	hq.push({ 0, N });
	
	
	while (N) {
		pair<int, int>p = hq.top();
		hq.pop();

		int weight = p.first, node = p.second;

		if (visited[node])
			continue;

		ans += weight;
		visited[node] = true;

		N--; // 방문하지 않은 정점일 때 카운팅

		for (int i = 0; i < graph[node].size(); i++) {
			int w = graph[node][i].first, n = graph[node][i].second;

			if (!visited[n]) 
				hq.push({ w, n });
			
		}
	}


	return ans;
}

int main() {
	int N, M;

	cin >> N >> M;
	
	while (M--) {
		int node1, node2, w;
		cin >> node1 >> node2 >> w;

		if (node1 == node2)
			continue;

		graph[node1].push_back({ w, node2 });
		graph[node2].push_back({ w, node1 });
	}
	

	cout << MST(N) << "\n";

	return 0;
}

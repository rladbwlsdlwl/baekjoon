#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001

using namespace std;
using pii = pair<int, int>;


// ascending, minheap
struct compare{
	bool operator()(pii node1, pii node2){
		if(node1.first == node2.first)
			return node1.second > node2. second;
		return node1.first > node2.first;
	}
};

// MST
// PRIM
// O(NlogN)

bool visited[MAX];
vector<pii> graph[MAX];

int MST(int V){
	int ans = 0;
	priority_queue<pii, vector<pii>, compare> hq; // {edgecost, node}

	fill_n(visited, MAX, false);
	hq.push({0, V});
	while(V){
		pii p = hq.top();
		int node = p.second, cost = p.first;

		hq.pop();

		if(visited[node])
			continue;

		ans += cost;
		visited[node] = true;
		for(int i = 0; i<graph[node].size(); i++){
			int child = graph[node][i].first, edge = graph[node][i].second;

			if(!visited[child])
				hq.push({edge, child});
		}

		V--;
	}

	return ans;
}

int main() {
	int V, E;
	cin >> V >> E;

	while(E--){
		int node1, node2, w;
		cin >> node1 >> node2 >> w;

		graph[node1].push_back({node2, w});
		graph[node2].push_back({node1, w});
	}

	cout << MST(V) << "\n";

	return 0;
}
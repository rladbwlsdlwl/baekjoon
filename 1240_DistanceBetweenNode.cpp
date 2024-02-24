#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;


int N, M;
vector<pair<int, int>> graph[MAX]; // {node, weight}
vector<pair<int, int>> query; // {node1, node2}
bool visited[MAX];

int ans = 0;
int dfs(int node, int goal){
	visited[node] = true;

	if(node == goal)
		return true;

	for(int i=0; i<graph[node].size(); i++){
		int child = graph[node][i].first;
		int cost = graph[node][i].second;
		if(!visited[child]){
			if(dfs(child, goal)){
				ans += cost;
				return true;
			}
		}
	}

	return false;
}

int main(){
	cin >> N >> M;

	while(--N){
		int node1, node2, cost;

		cin >> node1 >> node2 >> cost;
		graph[node1].push_back({node2, cost});
		graph[node2].push_back({node1, cost});
	}

	for(int i=0; i<M; i++){
		int node1, node2;
		cin >> node1 >> node2;

		query.push_back({node1, node2});
	}

	for(int i=0; i<M; i++){
		ans = 0;

		fill_n(visited, MAX, false);
		dfs(query[i].first, query[i].second);

		cout<< ans << "\n";
	}

	return 0;
}
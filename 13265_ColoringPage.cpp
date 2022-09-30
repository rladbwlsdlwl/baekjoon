#include<iostream>
#include<vector>
#include<queue>

#define MAX 1001


using namespace std;

vector<int>graph[MAX];

void bfs(int n) {
	bool visited[MAX]; // 방문유무를 체크
	fill_n(visited, MAX, false);
	
	bool colored[MAX]; // 노드의 색을 결정
	fill_n(colored, MAX, false); 

	queue<int>q;
	q.push(n);
	visited[n] = true;
	colored[n] = true; 

	bool stopped = false;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int connected_node = graph[node][i];

			if (!visited[connected_node]) {
				visited[connected_node] = true;
				colored[connected_node] = !colored[node];

				q.push(connected_node);
			}
			else {
				if (colored[node] == colored[connected_node]) {
					stopped = true;
					break;
				}
			}
		}
	}


	if (stopped)
		cout << "impossible\n";
	else
		cout << "possible\n";
}

int main() {
	int T;
	cin >> T;

	while(T--){
		int n, m;
		cin >> n >> m;

		int node1, node2;
		while (m--) {
			cin >> node1 >> node2;

			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		bfs(node1);
		
		for (int i = 1; i <= n; i++)
			graph[i].clear();
	}
}

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#define MAX 100001

using namespace std;
vector<int>graph[MAX];
unordered_map<int, bool>graphh[MAX];

// 간선의 길이
int getGraphEdge(int node, vector<bool>visited) {
	int cnt = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]])
			cnt++;
	}

	return cnt;
}

void bfs(vector<int>& cmd) {
	if (cmd[0] != 1) {
		cout << "0\n";
		return ;
	}

	vector<bool>visited(cmd.size() + 1, false);

	queue<int>q;
	q.push(1);
	visited[1] = true;

	bool stopped = false;
	int i = 1;
	while (!q.empty() && i < cmd.size()) {
		int node = q.front();
		q.pop();

		int graphEdge = getGraphEdge(node, visited);
		if (graphEdge > 0) {
			// 그래프에서 cmd의 정점이 존재하는지 check, 정점이 존재한다면 push
			bool check = false;
			for (int j = i; j < i + graphEdge; j++) {
				if (graphh[node].find(cmd[j]) != graphh[node].end()) {
					visited[cmd[j]] = true;
					q.push(cmd[j]);
				}
				else {
					check = true;
					break;
				}
			}

			if (check) {
				stopped = true;
				break;
			}
			i += graphEdge;
		}
	}

	cout << (stopped == false ? 1 : 0) << "\n";
}


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);

		graphh[node1][node2] = true;
		graphh[node2][node1] = true;
	}

	vector<int>cmd(N, 0);
	for (int i = 0; i < N; i++)
		cin >> cmd[i];

	bfs(cmd);

	return 0;
}

#include<iostream>
#include<vector>
#define MAX 50

using namespace std;

vector<int>graph[MAX];
int visited[MAX];
int ans = 0; // leaf node

void dfs(int parent, int d) {
	bool check = false;
	visited[parent] = true;

	for (int i = 0; i < graph[parent].size(); i++) {
		int next = graph[parent][i];
		if (next != d && visited[next] == false) {
			dfs(next, d);
			check = true;
		}
	}

	if (check==false)
		ans++;
}

int main() {
	int N;
	cin >> N;

	int root=-1,node;
	for (int i = 0; i < N; i++) {
		cin >> node;
		if (node == -1)
			root = i;
		else {
			graph[i].push_back(node); // parent
			graph[node].push_back(i); // child
		}
	}

	int remove;
	cin >> remove;

	fill_n(visited, MAX, false);
	if(root!=remove)
		dfs(root, remove);

	cout << ans << "\n";

	return 0;
}

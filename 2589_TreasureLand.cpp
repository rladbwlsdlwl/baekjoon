#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
// bruteforce

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, M;
char maze[50][50];

int ans = 0;

void bfs(int n, int m){
	vector<vector<bool>> visited(50, vector<bool>(50, false));
	queue<pair<pair<int, int>, int>> q; // {{r, c}, move}


	q.push({{n, m}, 0});
	visited[n][m] = true;
	while(!q.empty()){
		pair<int, int> p = q.front().first;
		int cnt = q.front().second;
		q.pop();

		ans = max(ans, cnt);

		for(int i=0; i<4; i++){
			int movey = dy[i] + p.first;
			int movex = dx[i] + p.second;

			if(movey >= 0 && movey < N && movex >= 0 && movex < M && !visited[movey][movex] && maze[movey][movex] == 'L'){
				visited[movey][movex] = true;
				q.push({{movey, movex}, cnt + 1});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			cin >> maze[i][j];
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M ;j++){
			if(maze[i][j] == 'L')
				bfs(i, j);
		}
	}

	cout << ans <<"\n";

	return 0;
}
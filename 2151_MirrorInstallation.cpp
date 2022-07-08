#include<iostream>
#include<queue> // BFS
#define MAX 50

struct Node {
	int y, x;
	int dir; // direction (E W S N)

	Node(int r, int c, int d) {
		y = r;
		x = c;
		dir = d; // 0 1 2 3
	}
};

using namespace std;

const int INF = 999999999;

int N;
char home[MAX][MAX]; // input
int dp[MAX][MAX][4];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

pair<int, int>startPos;
pair<int, int>endPos;

int bfs(queue<Node>&q) {
	while (!q.empty()) {
		Node top = q.front();
		q.pop();

		int moveY = top.y + dy[top.dir];
		int moveX = top.x + dx[top.dir];

		if (!(0 <= moveY && moveY < N && 0 <= moveX && moveX < N)) // range over
			continue;
		if (home[moveY][moveX] == '*')
			continue;
		
		if (home[moveY][moveX] == '#' && dp[moveY][moveX][top.dir] > dp[top.y][top.x][top.dir])
			dp[moveY][moveX][top.dir] = dp[top.y][top.x][top.dir];
		if (home[moveY][moveX] == '.' && dp[moveY][moveX][top.dir] > dp[top.y][top.x][top.dir]) { // 창문의 개수가 기존보다 적게 이동 가능한경우
			dp[moveY][moveX][top.dir] = dp[top.y][top.x][top.dir];
			q.push(Node(moveY, moveX, top.dir));
		}
		if (home[moveY][moveX] == '!') { 
			// 거울을 설치하지 않을 경우
			if (dp[moveY][moveX][top.dir] > dp[top.y][top.x][top.dir]) { 
				dp[moveY][moveX][top.dir] = dp[top.y][top.x][top.dir];
				q.push(Node(moveY, moveX, top.dir));
			}

			// 거울을 설치 할 경우 
			// 거울 반사
			if ((top.dir == 0 || top.dir == 1)) {   // E , W
				if (dp[moveY][moveX][2] > dp[top.y][top.x][top.dir] + 1) {
					dp[moveY][moveX][2] = dp[top.y][top.x][top.dir] + 1;
					q.push(Node(moveY, moveX, 2));
				}
				if (dp[moveY][moveX][3] > dp[top.y][top.x][top.dir] + 1) {
					dp[moveY][moveX][3] = dp[top.y][top.x][top.dir] + 1;
					q.push(Node(moveY, moveX, 3));
				}
			}
			else {
				if (dp[moveY][moveX][0] > dp[top.y][top.x][top.dir] + 1) {
					dp[moveY][moveX][0] = dp[top.y][top.x][top.dir] + 1;
					q.push(Node(moveY, moveX, 0));
				}
				if (dp[moveY][moveX][1] > dp[top.y][top.x][top.dir] + 1) {
					dp[moveY][moveX][1] = dp[top.y][top.x][top.dir] + 1;
					q.push(Node(moveY, moveX, 1));
				}
			}
		}
	}


	int ans = INF;
	for (int i = 0; i < 4; i++)
		ans = min(ans, dp[endPos.first][endPos.second][i]);

	return ans;
}

int main() {
	cin >> N;

	queue<Node>q;
	bool visited = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> home[i][j];
			if (home[i][j] == '#') { 
				if (!visited)
					startPos = { i,j };
				else
					endPos = { i,j };
				visited = true;
			}
			
			fill_n(dp[i][j], 4, INF);
		}
	}

	for (int i = 0; i < 4; i++) {
		dp[startPos.first][startPos.second][i] = 0;
		q.push(Node(startPos.first, startPos.second, i));
	}

	cout << bfs(q) << "\n";

	return 0;
}

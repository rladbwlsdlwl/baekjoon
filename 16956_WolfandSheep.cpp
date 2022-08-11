#include<iostream>
#include<vector>
#define MAX 500

using namespace std;

char road[MAX][MAX];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	int r, c;
	cin >> r >> c;

	vector<pair<int, int>>wolfPos;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> road[i][j];

			if (road[i][j] == 'W')
				wolfPos.push_back({ i,j });
		}
	}

	bool stopped = false;
	while (!wolfPos.empty() && !stopped) {
		pair<int,int>wolf = wolfPos.back();
		wolfPos.pop_back();

		for (int i = 0; i < 4; i++) {
			int y = dy[i] + wolf.first;
			int x = dx[i] + wolf.second;

			if (y < 0 || y >= r || x < 0 || x >= c || road[y][x]=='W') // 범위를 넘어서거나 늑대일경우
				continue; 
			else if (road[y][x] == 'S') { // 양일경우
				stopped = true;
				break;
			}
			else  // .일경우
				road[y][x] = 'D';
		}
	}

	if (stopped)
		cout << "0\n";
	else {
		cout << "1\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << road[i][j];
			cout << "\n";
		}
	}
	return 0;

}

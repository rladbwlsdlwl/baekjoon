#include<iostream>
#include<cmath> 
#include<cstdlib> //abs
#include<vector>
#define MAX 50
//#define int long long
const int INF = 1e9;
using namespace std;

int n, m;
int city[MAX][MAX];
vector <pair <int, int>> home, chicken, choice;
int dis = INF;

void dfs(int idx, int cnt) {
	if (cnt >= m) {
		int result = 0;
		for (int i = 0; i < home.size(); i++) {
			int ans = INF;
			for (int j = 0; j < m; j++) 
				ans = min(ans, abs(choice[j].first-home[i].first)+abs(choice[j].second-home[i].second));
			result += ans;
		}

		dis = min(dis, result);
	}
	else {
		for (int i = idx; i < chicken.size(); i++) {
			choice.push_back(chicken[i]);
			dfs(i+1,cnt+1);
			choice.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	dfs(0,0);

	cout << dis<< '\n';

	return 0;
}

#include<iostream>
#include<vector>
#define MAX 5

using namespace std;

int R, C, K;
bool visited[MAX+1][MAX+1];
int ans = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void dfs(int k, int r, int c){
	if(k==0){
		if(r==0 && c==C-1)
			ans++;

		return ;
	}


	for(int i=0; i<4; i++){
		int movey = dy[i] + r, movex = dx[i] + c;
		if(0 <= movey && movey < R && 0 <= movex && movex < C && !visited[movey][movex]){
			visited[movey][movex] = true;
			dfs(k-1, movey, movex);
			visited[movey][movex] = false;
		}
	}
}

int main(){
	cin>>R>>C>>K;

	for(int i=0; i<R; i++){
		char c;
		for(int j=0; j<C; j++){
			cin>>c;

			if(c == 'T')
				visited[i][j] = true;
		}
	}


	visited[R-1][0] = true;
	dfs(K-1, R-1, 0);

	cout<<ans<<"\n";

	return 0;
}
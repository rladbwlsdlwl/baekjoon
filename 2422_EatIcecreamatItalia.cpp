#include<iostream>
#include<vector>
#define MAX 200

using namespace std;


int N, M;
bool unable[MAX+1][MAX+1];
int ans = 0;

void dfs(int n, vector<int>visited){
	if(visited.size() == 3){

		// check unable combination
		int a = visited[0], b = visited[1], c = visited[2];
		if(!unable[a][b] && !unable[a][c] && !unable[b][c])
			ans++;

		return;
	}

	for(int i=n; i<=N; i++){
		visited.push_back(i);
		dfs(i+1, visited);
		visited.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i=0; i<=MAX; i++)
		fill_n(unable[i], MAX+1, false);


	for(int i=0; i<M; i++){
		int a, b;
		cin>>a>>b;

		unable[a][b] = true;
		unable[b][a] = true;
	}

	dfs(1, {});

	cout << ans << "\n";

	return 0;
}
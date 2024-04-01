#include<iostream>
#include<vector>


using namespace std;

int N;
vector<int>graph[100];
int visited[100][100];


void dfs(int n, int p){

	for(int i = 0; i<graph[p].size(); i++){
		int child = graph[p][i];

		if(visited[n][child] == 0){ // detect loop
			visited[n][child] = 1;

			dfs(n, child);
		}
	}

}

int main(){
	cin>>N;

	for(int i=0; i<N; i++){
		int node;
		for(int j=0;j<N;j++){
			cin>>node;

			if(node == 1)
				graph[i].push_back(j);
		}
	}


	for(int i = 0; i<N; i++)
		dfs(i, i);


	for(int i =0 ; i<N; i++){
		for(int j=0; j<N; j++)
			cout<<visited[i][j]<<" ";

		cout<<"\n";
	}


	return 0;
}


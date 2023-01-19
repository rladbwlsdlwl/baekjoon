/*
	graph와 union-find
*/

#include<iostream>
#include<vector>


using namespace std;

vector<int>graph[26];
int root[26]; // union-find

bool visited[26] = {false, };

int dfs(int parent){
	int cnt = 1;
	visited[parent] = true;

	for(int i=0; i<graph[parent].size(); i++){
		int child = graph[parent][i];

		if(!visited[child])
			cnt += dfs(child);

	}

	return cnt;
}

void UFinit(int size){
	for(int i=0; i<size; i++)
		root[i] = i;
}
int Find(int node){
	if(node!=root[node])
		return Find(root[node]);

	return node;
}
void Union(int parent, int child){
	int p = Find(parent);
	int c = Find(child);

	if(p!=c)
		root[child] = parent;
}

int main(){
	UFinit(26);

	int N, M;

	cin>>N>>M;

	char node1, node2;	
	while(M--){
		cin>>node1>>node2;

		graph[node1-'A'].push_back(node2-'A');

		Union(node1-'A', node2-'A');
	}


	int n;
	cin>>n;

	while(n--){
		cin>>node1;

		visited[node1-'A'] = true;
	}


	int ans = 0;
	for(int i=0; i<26; i++){
		int parent = Find(i);

		if(!visited[parent])
			ans+=dfs(parent)-1;

	}



	cout<<ans<<"\n";


	return 0;
}
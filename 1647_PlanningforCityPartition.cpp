#include<iostream>
#include<queue>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;

// min heap
struct compare{
	bool operator()(piii a, piii b){
		if(a.first == b.first)
			return a.second.first > b.second.first;
		return a.first > b.first;
	}
};

// MST - kruskal
// sort
priority_queue<piii, vector<piii>, compare> pq;
vector<int> UF;



// UF
vector<int> initUF(int n){
	vector<int> uf;
	for(int i=0; i<n; i++)
		uf.push_back(i);

	return uf;
}
int findUF(int node){
	if(node == UF[node])
		return node;
	return findUF(UF[node]);
}
void mergeUF(int parent1, int parent2){
	if(parent1 < parent2)
		UF[parent2] = parent1;
	else
		UF[parent1] = parent2;
}

int MST(int V){
	UF = initUF(V + 1);

	int ans = 0;
	while(V-2){
		piii p = pq.top();
		int cost = p.first, node1 = p.second.first, node2 = p.second.second;

		pq.pop();
		int parent1 = findUF(node1), parent2 = findUF(node2);
		if(parent1 != parent2){
			mergeUF(parent1, parent2);
			ans += cost;
			V--;
		}

	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	while(M--){
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		pq.push({cost, {node1, node2}});
	}

	cout << MST(N) << "\n";

	return 0;
}
#include<iostream>
#include<vector>

using namespace std;


int N;
int person[10];
int ans[10];

int findIdx(int order, int n){ // number order, current number
	for(int i=0; i<N; i++){
		if(order == 0 && ans[i] == -1) // blank pos
			return i;
		if(ans[i] == -1 || ans[i] > n)
			order--;
	}

	return -1;
}
int main(){
	cin >> N;

	for(int i=0; i<N; i++)
		cin >> person[i];

	fill_n(ans, 10, -1);

	for(int i=0; i<N; i++){
		int idx = findIdx(person[i], i+1);
		ans[idx] = i+1;
	}

	for(int i=0; i<N; i++)
		cout << ans[i] << " ";
	cout << "\n";


	return 0;
}
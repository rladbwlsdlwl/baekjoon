#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int P[10];

int min(int start, int end){
	int idx = start;
	for(int i=start; i<end; i++)
		idx = (P[idx] >= P[i] ? i : idx);

	return idx;
}

int findMaxSize(int cost){
	// 0의자리를 제외한 숫자 중 최소 원소를 찾음
	int idx = min(1, N);
	cost -= P[idx];

	if(N==1 || cost<=0)
		return 1;


	// 최소원소를 찾음
	idx = min(0, N);

	int size = 1;
	while(cost>=0){
		cost -= P[idx];
		size++;
	}

	return size-1;
}


int main(){
	cin >> N;

	for(int i=0; i<N; i++)
		cin>>P[i];


	cin >> M;

	int mxSize = findMaxSize(M);
	int mnIdx = min(0, N);



	int i = N-1;
	string ans = "";
	while(mxSize--){
		while(M - P[i] - P[mnIdx]*mxSize<0 && i>0)
			i--;

		ans += (i + '0');
		M -= P[i];
	}


	cout<<ans<<"\n";

	return 0;
}
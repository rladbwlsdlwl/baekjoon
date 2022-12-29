#include<iostream>
#define MAX 1000


using namespace std;


int song[51];
bool dp[51][MAX+1] = {false, };

int main (){
	int N, S, M;

	cin>>N>>S>>M;

	for(int i=1; i<=N; i++)
		cin>>song[i];


	bool stopped = false;
	dp[0][S] = true;
	for(int i=1; i<=N; i++){
		bool isValid = false;

		// 이전 노래까지의 가능한 음(모든 가능한 음을 셈)중 나를 더한 음이 가능한지를 찾는다
		for(int j=0; j<=M; j++){
			if(dp[i-1][j] && j+song[i] <= M){
				isValid = true;
				dp[i][j+song[i]] = true;
			}
			if(dp[i-1][j] && j-song[i] >= 0){
				isValid = true;
				dp[i][j-song[i]] = true;
			}
		}

		if(!isValid){
			stopped = true;
			break;
		}
	}

	int mx = 0;
	for(int i=M; i>=0; i--){
		if(dp[N][i]){
			mx = i;
			break;
		}
	}

	cout<<(stopped ? -1 : mx)<<"\n";

	return 0;
}
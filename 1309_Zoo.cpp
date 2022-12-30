#include<iostream>
#define MAX 100000

using namespace std;

// void dfs(int n, int put, int size){
// 	if(n==0){
// 		ans++;
// 		return ;
// 	}
// 	else if(size == N)
// 		return ;

// 	if(put == 0){
// 		dfs(n-1, 1, size+1);
// 		dfs(n, -1, size+1);
// 	}else if(put == 1){
// 		dfs(n-1, 0, size+1);
// 		dfs(n, -1, size+1);
// 	}else{
// 		dfs(n, 0, size+1);
// 		dfs(n, 1, size+1);
// 		dfs(n, -1, size+1);
// 	}
// }

int main(){
	int N;

	cin>>N;

	int dp[MAX+2] = {0, };

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4; i<=N+1; i++)
		dp[i] = (dp[i-1]*2 + dp[i-2]) % 9901;


	for(int i=2; i<=N+1; i++)
		dp[i] = (dp[i-1]+dp[i]) % 9901;



	cout<<dp[N+1]<<"\n";

	return 0;
}

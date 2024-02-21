#include<iostream>
#include<vector>

using namespace std;

int N;
vector<pair<int, int>> egg;
int ans = 0;

// {life, weight}
// bruteforce
void dfs(int n){
  if(n == N){
    int tmp = 0;
    for(int i=0; i<N; i++)
      tmp += egg[i].first <= 0? 1: 0;

    ans = max(ans, tmp);

    return;
  }
  if(egg[n].first <= 0) { // 자신의 계란이 깨져있을 경우
    dfs(n+1);
    return;
  }

  bool isFlag = false;
  for(int i=0; i<N; i++){
    if(i == n || egg[i].first <= 0) // 계란이 자기 자신일경우 || 상대 계란이 깨져있을 경우
      continue;

    isFlag = true;
    egg[n].first -= egg[i].second;
    egg[i].first -= egg[n].second;

    dfs(n+1);

    egg[n].first += egg[i].second;
    egg[i].first += egg[n].second;

  }

  if(!isFlag) // 깰 계란이 없을경우
    dfs(n+1);
}


int main(){
  cin >> N;

  for(int i = 0; i<N; i++){
    int a, b;
    cin >> a >> b;

    egg.push_back({a, b});
  }

  dfs(0);

  cout<< ans << "\n";

  return 0;
}
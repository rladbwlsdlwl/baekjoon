#include<iostream>
#include<cstring>
#include<cmath>

#define MAX 1000000
using namespace std;

void Solution_1929(int m,int n) {
	bool prime[MAX + 1];

	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i]) {
			for (int j = i*i; j <= n; j += i)
				prime[j] = false;
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i]) cout << i << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
	int m, n;
	cin >> m >> n;

	Solution_1929(m,n);

	return 0;
}

#include<iostream>
#include<cmath>
#define MAX 100

using namespace std;
int table[MAX];

void Solution_1978() {
	int n,result=0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> table[i];
		bool stopped = false;
		for (int j = 2; j <= sqrt(table[i]); j++) {
			if (table[i] % j == 0) {
				stopped = true;
				break;
			}
		}
		if (!stopped && table[i]!=1)
			result++;
	}

	cout << result << endl;
}
int main() {
	Solution_1978();

	return 0;
}


#include<iostream>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

void Solution_2609(int m,int n) {
	int num = GCD(m, n);
	cout << num << '\n' << m * n / num;
}

int main() {
	int m, n;
	cin >> m >> n;

	Solution_2609(m, n);
	return 0;
}

#include<iostream>

using namespace std;

long long int A, B, C;

long long int pow(long long int n, long long int cnt) {
	if (cnt == 0)
		return 1;
	else if (cnt == 1)
		return n;
	if (cnt % 2)
		return pow(n, cnt - 1) * n;

	long long int half = pow(n, cnt / 2) % C;
	return (half * half) % C;
}
int main() {
	cin >> A >> B >> C;

	cout << pow(A,B)%C << "\n";
	return 0;
}

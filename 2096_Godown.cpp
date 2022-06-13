#include<iostream>
#define MAX 100000

using namespace std;

int load[MAX][3];
int mn, mx;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> load[i][j];
	}

	int a = load[0][0], b = load[0][1], c = load[0][2];
	for (int i = 1; i < n; i++) {
		int tmp_a = min(a, b) + load[i][0];
		int tmp_b = (a <= b && a <= c ? a : (b <= a && b <= c ? b : c)) + load[i][1];
		int tmp_c = min(b, c) + load[i][2];
		a = tmp_a;
		b = tmp_b;
		c = tmp_c;
	}
	mn = (a <= b && a <= c ? a : (b <= a && b <= c ? b : c));

	a = load[0][0], b = load[0][1], c = load[0][2];
	for (int i = 1; i < n; i++) {
		int tmp_a = max(a, b) + load[i][0];
		int tmp_b = (a >= b && a >= c ? a : (b >= a && b >= c ? b : c)) + load[i][1];
		int tmp_c = max(b, c) + load[i][2];
		a = tmp_a;
		b = tmp_b;
		c = tmp_c;
	}

	mx = (a >= b && a >= c ? a : (b >= a && b >= c ? b : c));
	cout << mx << " " << mn << "\n";

	return 0;
}

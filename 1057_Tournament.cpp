#include<iostream>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	
	int ans = 0;
	while (a != b) {
		a = a - ((int)a / 2);
		b = b - ((int)b / 2);
		ans++;
	}

	cout << ans << "\n";
	return 0;
}

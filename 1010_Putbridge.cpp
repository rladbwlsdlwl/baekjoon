#include<iostream>

using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (b - a < a)
			a = b - a;

		long long ans = 1;
		for (int i = 0; i < a; i++)
			ans = ans * (b - i) / (i + 1);

		cout << ans << "\n";
	}

	return 0;
}

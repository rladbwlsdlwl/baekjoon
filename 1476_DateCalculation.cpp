#include<iostream>

using namespace std;
int main() {
	int E, S, M;
	cin >> E >> S >> M;

	int cnt = 1;
	int e = 1, s = 1, m = 1;

	while (!(E == e && S == s && M == m)) {
		e = (e + 1 > 15 ? 1 : e + 1);
		s = (s + 1 > 28 ? 1 : s + 1);
		m = (m + 1 > 19 ? 1 : m + 1);
		cnt++;
		//cout << e << " " << s << " " << m << "\n";
	}

	cout << cnt << "\n";
	return 0;
}

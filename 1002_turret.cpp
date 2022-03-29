#include<iostream>

using namespace std;
int main() {
	int t;
	cin >> t;

	long long x1, y1, d1, x2, y2, d2;
	long long dis, r, r_;
	while (t--) {
		cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

		if (x1 == x2 && y1 == y2) {
			if (d1 == d2) // 동일구간 
				cout << "-1\n";
			else
				cout << "0\n"; // 겹치는 구간이 존재하지 않음
		}
		else { // 접하거나 두점이 만나거나 안만나는경우가 존재
			dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
			r = (d1 + d2) * (d1 + d2);
			r_ = (d1 - d2) * (d1 - d2); // 내접

			if (dis == r || dis == r_) // 내접할 때 외접할 때
				cout << "1\n";
			else if (dis < r && r_ < dis) // 추가적인 조건으로 내부에 원이 존재할 때를 제외
				cout << "2\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}

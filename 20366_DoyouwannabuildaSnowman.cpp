#include<iostream>
#include<vector>
#include<algorithm> // use sort
#include<cstdlib> // use abs

const int INF = 999999999;
using namespace std;

int makeSnowman(vector<int>snow) {
	sort(snow.begin(), snow.end());
	int ans = INF;
	
	for (int i = 0; i < snow.size(); i++) {
		// Elsa
		for (int j = i + 3; j < snow.size(); j++) {
			int left = i + 1, right = j - 1; // Anna
			while (left < right) {
				int dis = (snow[i] + snow[j]) - (snow[left] + snow[right]);
				ans = min(ans, abs(dis));

				if (dis > 0) // if elsa is big
 					left++;
				else
					right--; // if anna is big
			}
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int>cmd(n);
	for (int i = 0; i < n; i++)
		cin >> cmd[i];

	cout << makeSnowman(cmd) << "\n";

	return 0;
}#include<iostream>
#include<vector>
#include<algorithm> // use sort
#include<cstdlib> // use abs

const int INF = 999999999;
using namespace std;

int makeSnowman(vector<int>snow) {
	sort(snow.begin(), snow.end());
	int ans = INF;
	
	for (int i = 0; i < snow.size(); i++) {
		// Elsa
		for (int j = i + 3; j < snow.size(); j++) {
			int left = i + 1, right = j - 1; // Anna
			while (left < right) {
				int dis = (snow[i] + snow[j]) - (snow[left] + snow[right]);
				ans = min(ans, abs(dis));

				if (dis > 0) // if elsa is big
 					left++;
				else
					right--; // if anna is big
			}
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int>cmd(n);
	for (int i = 0; i < n; i++)
		cin >> cmd[i];

	cout << makeSnowman(cmd) << "\n";

	return 0;
}

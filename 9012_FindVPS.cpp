#include<iostream>
#include<vector>
#include<string>

using namespace std;
void Solution_9012() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		bool stopped = false;
		vector <char> arr;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				arr.push_back(str[i]);
			if (str[i] == ')') {
				if (arr.size() == 0) {
					stopped = true;
					break;
				}
				arr.pop_back();
			}
		}
		cout << (!stopped && arr.size() == 0 ? "YES\n" : "NO\n");
	}
}

int main() {
	Solution_9012();

	return 0;
}

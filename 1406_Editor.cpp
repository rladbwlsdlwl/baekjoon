#include<iostream>
#include<vector>

using namespace std;

int main() {
	string s;
	vector <char> front; vector <char> back;

	cin >> s;
	for (int i = 0; i < s.size(); i++)
		front.push_back(s[i]);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (front.empty())
				continue;
			back.push_back(front.back());
			front.pop_back();
		}
		else if (cmd == 'D') {
			if (back.empty())
				continue;
			front.push_back(back.back());
			back.pop_back();
		}
		else if (cmd == 'B') {
			if (front.empty())
				continue;
			front.pop_back();
		}
		else if (cmd == 'P') {
			cin >> cmd;
			front.push_back(cmd);
		}

	}
	
	for (int i = 0; i < front.size(); i++)
		cout << front[i];
	for (int i = back.size() - 1; i >= 0; i--)
		cout << back[i];


	return 0;
}

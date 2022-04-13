#include<iostream>
#include<vector>

using namespace std;

void get_palindrome(string name) {
	vector<int>cntable(26, 0);
	for (int i = 0; i < name.size(); i++)
		cntable[name[i] - 'A']++;

	char word_;
	bool stopped = false;
	bool check_odd = false;
	vector<char>ans(name.size());
	for (int j = 0; j < name.size() / 2; j++) {
		char word;
		for (int i = 0; i < 26; i++) {
			if (cntable[i] > 0) {
				if (cntable[i] == 1) {
					cntable[i] = 0;
					if (!check_odd && name.size() % 2) {
						word_ = i + 'A';
						check_odd = true;
						continue;
					}
					stopped = true;
					break;
				}
				word = i + 'A';
				cntable[i] -= 2;
				break;
			}
		}
		if (stopped)
			break;

		ans[j] = word;
		ans[ans.size() - 1 - j] = word;
	}


	if (stopped)
		cout << "I'm Sorry Hansoo";
	else {
		if (name.size() % 2) {
			if (!check_odd) {
				for (int i = 0; i < 26; i++) {
					if (cntable[i]) {
						ans[ans.size() / 2] = i + 'A';
						break;
					}
				}
			}
			else
				ans[name.size() / 2] = word_;
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << "\n";
	}
}
int main() {
	string name;
	cin >> name;

	get_palindrome(name);

	return 0;
}


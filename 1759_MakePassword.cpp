#include<iostream>
#include<vector>

using namespace std;

vector<bool>cmd(26, false); 
vector<bool>visited(26, false);
int L, C;

void dfs(int c, int v, int i_) { // consonant(모음), vowel(자음)
	if (c == L - 1 || v == L)
		return;
	if (c + v == L) {
		for (int i = 0; i < 26; i++) {
			if (visited[i])
				cout << char('a' + i);
		}
		cout << "\n";
		return;
	}

	for (int i = i_; i < 26; i++) {
		if (cmd[i] && !visited[i]) {
			visited[i] = true;
			if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
				dfs(c + 1, v, i + 1);
			else
				dfs(c, v + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> L >> C;

	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		cmd[c - 'a'] = true;
	}

	dfs(0, 0, 0);

	return 0;
}

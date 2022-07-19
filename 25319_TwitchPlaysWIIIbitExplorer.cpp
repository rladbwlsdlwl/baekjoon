#include<iostream>
#include<vector>
#include<algorithm>

struct Node {
	int y;
	int x;

	Node(int r, int c) {
		y = r;
		x = c;
	}
};

using namespace std;


vector<Node>land[26];
vector<int>alphabet(26, 0); // count alphabet
vector<char>moved;

void moving(Node before, Node after) {
	if (before.y != after.y) {
		if (before.y < after.y) {
			moved.push_back('D');
			moving(Node(before.y + 1, before.x), after);
		}
		else {
			moved.push_back('U');
			moving(Node(before.y - 1, before.x), after);
		}
	}
	else if (before.x != after.x) {
		if (before.x < after.x) {
			moved.push_back('R');
			moving(Node(before.y, before.x + 1), after);
		}
		else {
			moved.push_back('L');
			moving(Node(before.y, before.x - 1), after);
		}
	}
	else
		moved.push_back('P');
}

bool move() {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > land[i].size())
			return false;
	}

	return true;
}


int main() {
	int N, M, S;
	cin >> N >> M >> S;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;

			land[c - 'a'].push_back(Node(i,j));
		}
	}

	char s[1000];
	for (int i = 0; i < S; i++) {
		cin >> s[i];
		alphabet[s[i] - 'a']++;
	}

	
	int C = 0;
	Node pos = Node(0, 0);
	
	while (move()) {
		for (int i = 0; i < S; i++) {
			moving(pos, land[s[i] - 'a'].back());

			pos = land[s[i] - 'a'].back();
			land[s[i] - 'a'].pop_back();
		}
		C++;
	}

	moving(pos, Node(N - 1, M - 1));
	moved.pop_back(); // remove P

	cout << C << " " << moved.size() << "\n";
	for_each(moved.begin(), moved.end(), [](auto& n) {
		cout << n;
	});
	

	return 0;
}

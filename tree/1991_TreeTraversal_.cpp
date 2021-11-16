#include<iostream>
#include<vector>
#define MAX 26

using namespace std;

vector<int>tree[MAX];

void preorder(int n) {
	if (n >= 0) {
		cout << char(n + 'A');
		preorder(tree[n][0]);
		preorder(tree[n][1]);
	}
}

void inorder(int n) {
	if (n >= 0) {
		inorder(tree[n][0]);
		cout << char(n + 'A');
		inorder(tree[n][1]);
	}
}

void postorder(int n) {
	if (n >= 0) {
		postorder(tree[n][0]);
		postorder(tree[n][1]);
		cout << char(n + 'A');
	}
}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char p, c1, c2;
		cin >> p >> c1 >> c2;
		
		tree[p - 'A'].push_back(c1-'A'); // .이면 음수를 추가함
		tree[p - 'A'].push_back(c2 - 'A');
	}
	
	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0); cout << "\n";

	return 0;
}

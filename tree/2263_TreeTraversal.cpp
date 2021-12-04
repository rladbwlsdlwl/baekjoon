#include<iostream>
#define MAX 100001

using namespace std;

int inorder[MAX];
int postorder[MAX];
int inIdx[MAX]; // save index

void dfs(int inleft, int inright, int postleft, int postright) {
	if (inleft > inright || postleft > postright)
		return;

	int rootIdx = inIdx[postorder[postright]];
	cout << inorder[rootIdx] << " ";

	int leftSize = rootIdx - inleft;
	int rightSize = inright - rootIdx;

	dfs(inleft, rootIdx - 1, postleft, postleft + leftSize - 1);
	dfs(rootIdx + 1, inright, postleft + leftSize, postright - 1);
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		inIdx[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) 
		cin >> postorder[i];
	
	dfs(0, n - 1, 0, n - 1);
	return 0;
}

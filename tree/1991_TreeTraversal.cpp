#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	char val;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

void preorder(TreeNode* p) {
	if (p) {
		cout << p->val;
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(TreeNode* p) {
	if (p) {
		inorder(p->left);
		cout << p->val;
		inorder(p->right);
	}
}
void postorder(TreeNode* p) {
	if (p) {
		postorder(p->left);
		postorder(p->right);
		cout << p->val;
	}
}

int main() {
	int n;
	cin >> n;
	
	TreeNode* root;
	vector<TreeNode> stk(26);

	for (int i = 0; i < n; i++) {
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;

		stk[parent - 'A'].val = parent;
		if(child1!='.')
			stk[parent - 'A'].left = &stk[child1 - 'A'];
		if (child2 != '.')
			stk[parent - 'A'].right = &stk[child2 - 'A'];

	}

	root = &stk[0];
	preorder(root); cout << "\n";
	inorder(root); cout << "\n";
	postorder(root); cout << "\n";
	
	return 0;
}

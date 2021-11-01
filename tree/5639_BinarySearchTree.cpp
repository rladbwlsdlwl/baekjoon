#include<iostream>
using namespace std;


typedef struct TreeNode {
	int val;
	TreeNode* left=NULL;
	TreeNode* right=NULL;
};


TreeNode* insertion(TreeNode* node, int n) {
	if (!node) {
		node = new TreeNode(); // malloc
		node->val = n;
	}
	else {
		if (node->val > n)
			node->left = insertion(node->left, n);
		else
			node->right = insertion(node->right, n);
	}

	return node;
}


void postorder(TreeNode* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		cout << node->val << "\n";
	}
}

int main() {
	int n;
	TreeNode* root = NULL;

	//프로그램 종료할 때까지 입력받음 (ctrl + z)
 
	while (true) {
		cin >> n;
		if (cin.eof())
			break;
		root = insertion(root, n);
	}

	postorder(root);
	return 0;

}



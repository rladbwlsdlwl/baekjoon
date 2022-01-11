#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

int ans[MAX];
int main() {
	int n;
	cin >> n;

	// input
	vector<int>A(n);
	for (int i = 0; i < n; i++) 
		cin >> A[i];
	

	// answer
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		while (idx.size() && A[idx.back()] < A[i]) { // pop increase value
			ans[idx.back()] = A[i];
			idx.pop_back();
		}

		idx.push_back(i); // push decrease value
	}
	
	while (idx.size()) {
		ans[idx.back()] = -1;
		idx.pop_back();
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;

}

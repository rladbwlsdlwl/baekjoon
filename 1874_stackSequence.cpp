#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num[100001];
	for (int i = 0; i < n; i++)
		cin >> num[i];

	vector<int>stk;
	vector<char>op;

	int p = 1;
	bool stopped = false;
	for (int i = 0; i < n; i++) {
		if (p > num[i]) {
			
			if (stk.empty() || stk.back()!=num[i]) {
				stopped = true;
				break;
			}

			stk.pop_back();
			op.push_back('-');

		}
		else {
			while(p<=num[i]){
				stk.push_back(p);
				op.push_back('+');
				p++;
			}
			stk.pop_back();
			op.push_back('-');
		}
	}

	if (stopped)
		cout << "NO" << '\n';
	else {
		for (int i = 0; i < op.size(); i++)
			cout << op[i] << '\n';
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
void solution_10867();

int main() {
	solution_10867();

	return 0;
}

void solution_10867() {
	int n; 
	vector <int> table; set <int> temp; int num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		temp.insert(num);
	}

	for (auto iter = temp.begin(); iter != temp.end(); iter++)
		cout << *iter<<' ';

}

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

class Solution {
private:
	vector <string> alphabet;
public:
	void WordSort();
	void Print();

	Solution() {
		int n; string temp;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> temp;
			alphabet.push_back(temp);
		}
	}
};

bool compare(string a, string b) {

	if (a.size() == b.size())
		return a < b; // ASCII ascending sort
	else
		return a.size() < b.size(); // string length ascending sort

}

void Solution::WordSort() {
	sort(alphabet.begin(), alphabet.end(), compare);
	alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());
}

void Solution::Print() {
	for (int i = 0; i < alphabet.size(); i++)
		cout << alphabet[i] << '\n';
}

int main() {
	Solution sol=Solution();
	sol.WordSort();
	sol.Print();

	return 0;
}


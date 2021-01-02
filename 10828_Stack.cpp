#include<iostream>
#include<stack>
#include<string>

using namespace std;
void solution_10828();

int main() {
	solution_10828();

	return 0;
}

void solution_10828() {
	int n,num;
	cin >> n;

	stack <int> s;
	string query;

	for (int i = 0; i < n; i++) {
		cin >> query;

		if (query == "push") {
			cin >> num;
			s.push(num);
		}
		else if (query == "pop") {
			if (s.size()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (query == "size")
			cout << s.size() << '\n';
		else if (query == "empty")
			cout << (s.empty() == true ? 1 : 0) << '\n';
		else
			cout << (s.size() ? s.top() : -1) << '\n';
	}

}

#include<iostream>
#include<vector>

using namespace std;

int main() {
	string N;
	cin >> N;


	int i;
	vector<char>ans;
	bool stopped = false;
	for (i = 0; i < N.size(); i++) {
		if (N[i] == '7' || N[i] == '4')
			ans.push_back(N[i]);
		else if (N[i] > '7') {
			i++;
			ans.push_back('7');
			break;
		}
		else if (N[i] > '4') {
			i++;
			ans.push_back('4');
			break;
		}
		else {
			stopped = true;
			break;
		}
	}

	
	while (stopped && !ans.empty() && ans.back() == '4') {
		i--;
		ans.pop_back();
	}

	if (stopped) {
		if (ans.empty())
			i++;
		else {
			ans.pop_back(); // pop 7
			ans.push_back('4'); 
		}
	}
	
	
	for (; i < N.size(); i++)
		ans.push_back('7');
	

	for (auto n : ans)
		cout << n;

	return 0;
}

#include<iostream>

using namespace std;
int main() {
	string s, t;
	cin >> s >> t;

	string sList;
	for (int i = 0; i < s.size(); i++) {
		if (! ('0' <= s[i] && s[i]<='9'))
			sList += s[i];
	}

	size_t nPos = sList.find(t);
	if (nPos != string::npos)
		cout << "1";
	else
		cout << "0";

	return 0;
}

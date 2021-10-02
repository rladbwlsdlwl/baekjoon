#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	string cmd;
	getline(cin, cmd);

	vector<char>temp;
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == 'U' && temp.size() == 0)
			temp.push_back(cmd[i]);
		else if (cmd[i] == 'C' && ((temp.size() == 1) || temp.size() == 3))
			temp.push_back(cmd[i]);
		else if (cmd[i] == 'P' && temp.size() == 2)
			temp.push_back(cmd[i]);
	}

	if (temp.size() == 4)
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";
	

	return 0;
}


#include<iostream>
#include<deque>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n; //cin.get();
	for (int i = 0; i < n; i++) {
		string cmd,arr; int size;
		
		cin >> cmd >> size >> arr;

		deque<int>deq; int num=0;
		for (int j = 0; j < arr.size(); j++) { 
			if (arr[j] == '[' || arr[j] == ']')
				continue;
			else if (arr[j] != ',') {

				num = num * 10 + arr[j] - '0';
			}
			else {
				deq.push_back(num);
				num = 0;
			}
		}
		
		if(size>0)
			deq.push_back(num);
	

		bool top = false;
		bool stopped = false;
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R')
				top = !top;
			else if (cmd[j] == 'D') {
				if (deq.empty()) {
					stopped = true;
					break;
				}
				if (top)
					deq.pop_back();
				else
					deq.pop_front();
			}
		}
		

		if (stopped)
			cout << "error\n";
		else {
			if (deq.empty()) 
				cout << "[]\n";
			
			else if (top) {
				cout << '[';
				for (int j = deq.size() - 1; j > 0; j--)
					cout << deq[j] << ',';
				cout << deq[0] << "]\n";
			}
			else {
				cout << '[';
				for (int j = 0; j < deq.size() - 1; j++)
					cout << deq[j] << ',';
				cout << deq[deq.size() - 1] << "]\n";
			}
		}


	
	}
	

	return 0;
}

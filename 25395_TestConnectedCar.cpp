#include<iostream>
#include<vector>

#define MAX 1000000

using namespace std;

int car[MAX];
int fuel[MAX];
bool visited[MAX] = { false, };

int main() {
	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> car[i];
	for (int i = 0; i < N; i++)
		cin >> fuel[i];

	visited[S - 1] = true;
	bool isValid = true; // 더 연결될 가능성이 있다면
	while (isValid) {
		isValid = false;

		// moving left
		for (int i = S - 1; i >= 1; i--) {
			if (car[i] - car[i - 1] <= fuel[i]) {
				fuel[i - 1] = max(fuel[i - 1], fuel[i] - (car[i] - car[i - 1]));
				visited[i - 1] = true;
			}
			else // 더 이상 움직이지 못함
				break;
			if (fuel[i - 1] - (car[S - 1] - car[i - 1]) > fuel[S - 1]) {
				isValid = true;
				fuel[S - 1] = fuel[i - 1] - (car[S - 1] - car[i - 1]);
			}
		}

		// moving right
		for (int i = S - 1; i < N - 1; i++) {
			if (car[i + 1] - car[i] <= fuel[i]) {
				fuel[i + 1] = max(fuel[i + 1], fuel[i] - (car[i + 1] - car[i]));
				visited[i + 1] = true;
			}
			else
				break;
			if (fuel[i + 1] - (car[i + 1] - car[S - 1]) > fuel[S - 1]) {
				isValid = true;
				fuel[S - 1] = fuel[i + 1] - (car[i + 1] - car[S - 1]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])
			cout << i + 1 << " ";
	}

	return 0;
}

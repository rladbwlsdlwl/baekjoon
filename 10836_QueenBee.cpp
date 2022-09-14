#include<iostream>
#include<vector>

using namespace std;

int M, N;

int main() {
	cin >> M >> N; 

	int zero, one, two;
	vector<int>bee(2 * M - 1, 1); // 가장자리 애벌레 생성

	// 가장자리 애벌레들을 먼저 성장시킴
	while (N--) {
		cin >> zero >> one >> two;
		
		for (int i = zero; i < zero + one; i++)
			bee[i]++;
		for (int i = zero + one; i < zero + one + two; i++)
			bee[i] += 2;
	}


	// 나머지 애벌레 포함하여 2차원 형태로 출력
	for (int i = M - 1; i >= 0; i--) {
		cout << bee[i] << " ";
		for (int j = M; j < 2 * M - 1; j++)
			cout << bee[j] << " ";

		cout << "\n";
	}

	return 0;
}

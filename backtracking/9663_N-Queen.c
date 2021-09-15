#define CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int cnt = 0;
int N = 0;
int *chess;

void solution();
void dfs(int n);
bool checkQueen(int n, int size);

int main() {
	scanf("%d", &N);	
	solution();
	printf("%d\n", cnt);

	return 0;
}

void solution() {
	chess = malloc(sizeof(int) * N);
	dfs(N);
	
	free(chess);
}

void dfs(int n) {
	if (n == 0)
		cnt++;
	else {
		for (int i = 0; i < N; i++) {
			if (checkQueen(i, N - n)) {
				chess[N - n] = i;
				dfs(n - 1);
			}
		}
	}
}

bool checkQueen(int n, int size) {
	for (int i = 0; i < size; i++) {
		if (chess[i] == n || abs(chess[i] - n) == size - i)
			return false;
	}

	return true;
}


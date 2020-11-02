#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define Maxsize 1000001
int min(int a, int b, int c) {
	int arr[3] = { a,b,c };
	int tmp;
	for (int i = 2; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
		}
	}
	return arr[0];
}


int main() {
	int number;
	int cnt;
	scanf("%d", &number);
	int* dp = (int*)malloc(sizeof(int) * number + 1);
	memset(dp, 0, sizeof(dp));
	dp[2] = 1, dp[3] = 1;
	for (int i = 4; i <= number; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = 1 + min(dp[i / 3], dp[i / 2], dp[i - 1]);
		}
		else if (i % 3 != 0 && i % 2 != 0) {
			dp[i] = 1 + dp[i - 1];
		}
		else {
			if (i % 3 == 0) { cnt = (dp[i / 3] >= dp[i - 1]) ? dp[i - 1] : dp[i / 3]; }
			if (i % 2 == 0) { cnt = (dp[i / 2] >= dp[i - 1]) ? dp[i - 1] : dp[i / 2]; }
			dp[i] = 1 + cnt;
		}

	}
	printf("%d", dp[number]);
	return 0;
}
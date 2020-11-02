#include <iostream>
#include <algorithm>
#include <set>
#define MaxSize 250001
int level[MaxSize] = { 0, };		//level arr 0으로 초기화

using namespace std;
set<int>setnode;

int main() {
	int N;
	int buff,levelbuff;
	scanf("%d", &N);
	
	int left, right;
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &buff);
		auto iter = setnode.lower_bound(buff);
		if (iter == setnode.begin()) {
			left = 0;
		}
		else {
			auto l_iter = iter;
			left = level[*(--l_iter)];
		}
		if (iter == setnode.end()) {
			right = 0;
		}
		else {
			auto r_iter = iter;
			right = level[*(r_iter)];
		}
		level[buff] = max(left, right) + 1;
		setnode.insert(buff);
		
		sum += level[buff];
	}

	cout << sum;
	return 0;
}
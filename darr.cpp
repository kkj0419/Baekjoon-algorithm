#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int numa, numb;
	vector<int>arra;
	vector<int>arrb;
	scanf("%d %d", &numa, &numb);
	int i,input;
	for (i = 0; i < numa; i++) {
		scanf("%d", &input);
		arra.push_back(input);
	}
	for (i = 0; i < numb; i++) {
		scanf("%d", &input);
		arrb.push_back(input);
	}
	// vector input
	sort(arra.begin(), arra.end());
	sort(arrb.begin(), arrb.end());	//sort

	int a = 0, b = 0;		//pointer set
	vector<int>inputv;		//input�� vector set
	while (a < arra.size() && b < arrb.size()) {	//���̻� Ž���� ���� ���� ��
		if (arra[a] == arrb[b])
			a++, b++;
		else {
			if (arra[a] > arrb[b]) {
				b++;
			}
			else {
				inputv.push_back(arra[a]);
				a++;
			}
		}
	}
	if (a != arra.size()) {		//arra���� ����
		for (i = a; i < arra.size(); i++) {
			inputv.push_back(arra[i]);
		}
	}

	printf("%d\n", inputv.size());
	for (i = 0; i < inputv.size(); i++) {
		if (i == inputv.size() - 1)	printf("%d", inputv[i]);
		else
		{
			printf("%d ", inputv[i]);
		}
	}

	return 0;
}
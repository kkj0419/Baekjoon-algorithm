#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> s; //����Ʈ�� ����

int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
	int input;
	for (int i = 0; i < A; i++)
    {
		scanf("%d", &input);
        s.insert(input);
    }

	set<int>::iterator iter;		//set�� ���� iterator ����

    for (int i = 0; i < B; i++)
    {
		scanf("%d", &input);
		iter = s.find(input);
        if (iter == s.end())
            continue;
        else
            s.erase(iter);			//��ġ�ϴ� �� ������ �� erase ����
    }

	printf("%d\n", s.size());
	for (iter = s.begin(); iter != s.end();iter++) {
		printf("%d ", *iter);
	}
	
	return 0;
}

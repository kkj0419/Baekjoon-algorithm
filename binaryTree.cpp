#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
vector<int>cnt;

typedef struct _Vertex {
	int value;
	_Vertex* leftchild;			//pointer ����
	_Vertex* rightchild;
}Vertex;

Vertex* createVertex(int value) {
	Vertex* node=(Vertex*)malloc(sizeof(Vertex));
	node->leftchild = NULL;
	node->rightchild = NULL;
	node->value = value;
	return node;
}
void insert(Vertex* V, int X) {
	if (X < V->value) {
		if (V->leftchild) {				//leftchild ����
			insert((V->leftchild), X);
		}
		else {			//left insert
			V->leftchild = createVertex(X);
		}
	}
	else {				//right insert
		if (V->rightchild) {
			insert(V->rightchild,X);
		}
		else {
			V->rightchild = createVertex(X);
		}
	}
}

int height(Vertex* root,int value) {
	Vertex* v = root;		//search ���� node
	int h = 1;
	while (1) {
		if (value < v->value) {
			v = v->leftchild;
			h++;
		}
		else if (value > v->value) {
			v = v->rightchild;
			h++;
		}
		else {		//��ġ
			break;
		}
	}
	return h;
}

void search(Vertex* root,int high) {	//���� �� ����
	
	cnt[high]++;

	while () {
		if (root->leftchild) {

		}
	}
	if (root->leftchild) {				//leftchild ���� �� count
		search(root->leftchild,high+1);
	}
	if (root->rightchild) {
		search(root->rightchild,high+1);
	}

}
int main() {

	int N, buff;
	scanf("%d", &N);
	int* P = (int*)malloc(sizeof(int) * N);		//N size arr 
	for (int i = 0; i < N; i++) {		//�迭�� �� ����
		scanf("%d", &buff);
		P[i] = buff;
	}
	Vertex* root = createVertex(P[0]);

	for (int i = 1; i <= N - 1; i++) {
		insert(root, P[i]);
	}

	cnt.resize(N, 0);
	search(root,1);

	int sum = 0;
	for (int i = 1; i < cnt.size(); i++) {
		sum += cnt[i]*i;
	}
	printf("%d",sum);
	return 0;
}
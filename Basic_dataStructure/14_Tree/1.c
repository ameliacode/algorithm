#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 100

typedef struct treeNode {
	int data;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode *createNode(int data) {
	treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

treeNode *searchNode(treeNode *root, int x) {

	treeNode *temp = NULL;
	if (root->data == x) {
		//printf("Searched:%d\n", root->data);
		return root;
	}

	if (root->left != NULL) {
		temp = searchNode(root->left, x);
		if (temp != NULL) return temp;
	}
	if (root->right != NULL) {
		temp = searchNode(root->right, x);
		if (temp != NULL) return temp;
	}
	return temp;
	//temp에서 반환하기 위해 반드시 필요하다!!!

}//by Han 

//루트가 있다고 가정하자
treeNode* makeRootNode(treeNode *root, int data, int leftData, int rightData) {
	treeNode *p = NULL;
	treeNode *leftNode;
	treeNode *rightNode;

	p = searchNode(root, data);
	if (p == NULL) {
		//printf("FAILED TO SEARCH\n");
		return 0;
	}

	if (leftData != 0) {
		leftNode = createNode(leftData);
		p->left = leftNode;
	}
	if (rightData != 0) {
		rightNode = createNode(rightData);
		p->right = rightNode;
	}
}

void preNode(treeNode *root) {
	if (root) {
		preNode(root->left);
		printf("%d ", root->data);
		preNode(root->right);
	}
}

//유효하지 않은 정보들은 입력하지 않는다고 가정
void visitNode(treeNode *root, char info[]) {
	treeNode *p = root;
	int i, len;
	len = strlen(info);

	printf(" %d", p->data);
	for (i = 0; i < len; i++) {
		if (info[i] == 'L') {
			p = p->left;
			printf(" %d", p->data);
		}
		else if (info[i] == 'R') {
			p = p->right;
			printf(" %d", p->data);
		}
	}
	printf("\n");
}

int main() {

	int N, searchNum;
	int parent, left, right;
	char input[101] = "";
	treeNode *Tree;

	scanf("%d", &N);
	scanf("%d %d %d", &parent, &left, &right);

	//루트 만들기
	Tree = createNode(parent);
	Tree->left = createNode(left);
	Tree->right = createNode(right);

	while (N - 1) {
		scanf("%d %d %d", &parent, &left, &right);
		makeRootNode(Tree, parent, left, right);
		//preNode(Tree);
		//printf("\n");
		N--;
	}

	scanf("%d", &searchNum);

	while (searchNum) {
		scanf("%s", input);
		visitNode(Tree, input);
		searchNum--;
	}

	return 0;
}

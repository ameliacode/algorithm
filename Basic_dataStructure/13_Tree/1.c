#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min = 0;
int max = 0;

typedef struct treeNode {
	int data;
	int rank;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode *makeRootNode(int data, int rank, treeNode* leftNode, treeNode* rightNode) {
	treeNode *root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->rank = rank;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

/*treeNode *searchNode(int rank, treeNode* root) {
	if (root) {
		if (rank == root->rank) return root;
		else if(rank > root->rank) {
			searchNode(rank, root->left);
			searchNode(rank, root->right);
		}
	}
}*/

void preNode(treeNode *root) {
	if (root) {
		printf("%d ", root->data);
		preNode(root->left);
		preNode(root->right);
	}
}

void printLRNodes(treeNode *root) {
	if (!root) printf("-1\n");
	else {
		printf("%d ", root->data);
		if (root->left) printf("%d ", root->left->data);
		if (root->right) printf("%d ", root->right->data);
	}
}

int main() {

	treeNode *n[8] = { NULL };

	n[7] = makeRootNode(80, 8, NULL, NULL);
	n[6] = makeRootNode(130, 7, NULL, NULL);
	n[5] = makeRootNode(120, 6, n[6], n[7]);
	n[4] = makeRootNode(90, 5, NULL, NULL);
	n[3] = makeRootNode(70, 4, NULL, NULL);
	n[2] = makeRootNode(50, 3, NULL, n[5]);
	n[1] = makeRootNode(30, 2, n[3], n[4]);
	n[0] = makeRootNode(20, 1, n[1], n[2]);

	int input;
	int i;
	treeNode *std =  NULL;
	treeNode *root = n[0];

	scanf("%d", &input);
	std = n[input-1];
	if(input<9)printLRNodes(std);
	else printf("-1\n");

	return 0;
}

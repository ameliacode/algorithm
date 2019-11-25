#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treeNode {
	int key;
	struct treeNode* parent;
	struct treeNode* LChild;
	struct treeNode* RChild;
}treeNode;

typedef struct {
	treeNode *root;
}Tree;

treeNode *makeRootNode(void) {
	Tree *tree;
	tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}
treeNode* getNode() {
	treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->key = NULL;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	newNode->parent = NULL;
	return newNode;
}

Tree *tree;

int isExternal(treeNode *w);
treeNode *findElement(Tree* T, int k);
treeNode *treeSearch(treeNode *v, int k);
void insertItem(int k);
treeNode* removeElement(int k);
treeNode* inOrderSucc(treeNode* w);
void prePrint(treeNode *root);
void expandExternal(treeNode *w);
treeNode* reduceExternal(treeNode *z);
treeNode* sibling(treeNode *w);
int isRoot(treeNode *z);

int main() {

	int num;
	int exitFlag = 1;
	char oper;
	tree = makeRootNode();
	tree->root = getNode();
	treeNode *temp;

	while (exitFlag) {
		scanf("%c", &oper);
		getchar();
		switch (oper) {
		case 'i':
			scanf("%d", &num);
			getchar();
			insertItem(num);
			break;
		case 'd':
			scanf("%d", &num);
			getchar();
			temp = removeElement(num);
			if (temp == NULL) {
				printf("X\n");
			}
			else printf("%d\n", num);
			break;
		case 's':
			scanf("%d", &num);
			getchar();
			temp = findElement(tree, num);
			if (temp == NULL) {
				printf("X\n");
			}
			else printf("%d\n", temp->key);
			break;
		case 'p':
			prePrint(tree->root);
			printf("\n");
			break;
		case 'q':
			exitFlag = 0;
			break;
		}
	}

	return 0;
}

treeNode *findElement(Tree* T, int k) {
	treeNode *w = treeSearch(T->root, k);
	if (isExternal(w))
		return NULL;
	else return w;
}

int isExternal(treeNode *w) {
	if (w->LChild == NULL && w->RChild == NULL)
		return 1;
	else
		return 0;
}

int isRoot(treeNode *z) {
	if (z->parent == NULL) return 1;
	else return 0;
}

treeNode *treeSearch(treeNode *v, int k) {

	if (isExternal(v)) {
		return v;
	}

	if (k == v->key)
		return v;
	else if (k < v->key) {
		;
		return treeSearch(v->LChild, k);
	}
	else {
		return treeSearch(v->RChild, k);
	}
}

void insertItem(int k) {
	treeNode *w = treeSearch(tree->root, k);
	if (!isExternal(w))
		return;
	else {
		w->key = k;
		expandExternal(w);
		return;
	}
}

treeNode* removeElement(int k) {
	treeNode* w = treeSearch(tree->root, k);

	if (isExternal(w))
		return NULL;

	treeNode *e = w;
	treeNode *z = w->LChild;
	treeNode *y;

	if (!isExternal(z))
		z = w->RChild;
	if (isExternal(z)) {
		reduceExternal(z);
	}
	else {
		y = inOrderSucc(w);
		z = y->LChild;
		w->key = y->key;
		reduceExternal(z);
	}
	return e;
}

treeNode *inOrderSucc(treeNode* w) {
	w = w->RChild;
	while (w->LChild != NULL) {
		w = w->LChild;
	}
	return w->parent;
}

void prePrint(treeNode *root) {
	if (root) {
		if (root->key != 0) printf(" %d", root->key);
		prePrint(root->LChild);
		prePrint(root->RChild);
	}
}

void expandExternal(treeNode *w) {
	treeNode *l = getNode();
	treeNode *r = getNode();
	l->parent = w;;
	r->parent = w;
	w->LChild = l;
	w->RChild = r;
	return;
}

treeNode* reduceExternal(treeNode *z) {

	treeNode *w = z->parent;	//ÀÌ ºÎºÐÀÌ ¾È µÊ..
	treeNode *zs = sibling(z);
	treeNode *g;

	if (isRoot(w)) {
		tree->root = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (w == g->LChild)
			g->LChild = zs;
		else
			g->RChild = zs;
	}
	free(z);
	free(w);
	return zs;
}

treeNode* sibling(treeNode *w) {
	if (w->parent->LChild == w) {
		return w->parent->RChild;
	}
	else {
		return w->parent->LChild;
	}
}//copyright github @ameliacode 2019

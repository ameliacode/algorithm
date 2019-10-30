#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treeNode {
	int key;
	int height;
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

int _max(int a, int b) {
	return a > b ? a : b;
}

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
void searchAndRepairAfterInsertion(treeNode *w);
void searchAndRepairAfterRemoval(treeNode *w);
int heightUpdateAndBalanceCheck(treeNode *w);
treeNode *restructure(treeNode *x);
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
			if (temp == NULL) printf("X\n");
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
		searchAndRepairAfterInsertion(w);
		return;
	}
}

treeNode* removeElement(int k) {
	treeNode* w = treeSearch(tree->root, k);

	if (isExternal(w))
		return NULL;

	treeNode *e = w;
	treeNode *z = w->LChild;
	treeNode *y, *zs;

	if (!isExternal(z))
		z = w->RChild;
	if (isExternal(z)) {
		zs = reduceExternal(z);
	}
	else {
		y = inOrderSucc(w);
		z = y->LChild;
		w->key = y->key;
		zs = reduceExternal(z);
	}
	searchAndRepairAfterRemoval(zs->parent);
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
	l->parent = w;
	l->height = 0;
	r->parent = w;
	r->height = 0;
	w->LChild = l;
	w->RChild = r;
	w->height = 1;
	return;
}

treeNode* reduceExternal(treeNode *z) {

	treeNode *w = z->parent;
	treeNode *zs = sibling(z);
	treeNode *g;

	if (w == NULL) {
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
	treeNode* w_parent = w->parent;
	if (w_parent->LChild == w) {
		return w_parent->RChild;
	}
	else {
		return w_parent->LChild;
	}
}

void searchAndRepairAfterInsertion(treeNode *w) {
	treeNode *z = w;
	treeNode *y;
	treeNode *x;

	while (heightUpdateAndBalanceCheck(z)) {
		if (isRoot(z))
			return;
		z = z->parent;
	}

	if (z->LChild->height > z->RChild->height)
		y = z->LChild;
	else
		y = z->RChild;

	if (y->LChild->height > y->RChild->height)
		x = y->LChild;
	else if (y->LChild->height < y->RChild->height)
		x = y->RChild;
	else
		x = y->LChild;
	restructure(x);
	return;
}

int heightUpdateAndBalanceCheck(treeNode *w) {

	treeNode *l, *r;
	int balance;

	if (w == NULL)
		return 1;

	l = w->LChild;
	r = w->RChild;

	w->height = _max(r->height, l->height) + 1;
	balance = abs(r->height - l->height);
	return balance < 2 ? 1 : 0;
}

treeNode *restructure(treeNode *x) {
	treeNode *y = x->parent;
	treeNode *z = y->parent;
	treeNode *z_parent = z->parent;
	treeNode *a, *b, *c;
	treeNode *T1, *T2, *T3, *T0;

	if (z->key < y->key && y->key < x->key) {
		a = z;	b = y;	c = x;
		T0 = a->LChild;	T1 = b->LChild;	T2 = c->LChild;	T3 = c->RChild;
	}
	else if (x->key < y->key && y->key < z->key) {
		a = x;	b = y;	c = z;
		T0 = a->LChild;	T1 = a->RChild;	T2 = b->RChild;	T3 = c->RChild;
	}
	else if (z->key < x->key && x->key < y->key) {
		a = z;	b = x;	c = y;
		T0 = a->LChild;	T1 = b->LChild;	T2 = b->RChild;	T3 = c->RChild;
	}
	else {
		a = y;	b = x;	c = z;
		T0 = a->LChild;	T1 = b->LChild;	T2 = b->RChild;	T3 = c->RChild;
	}

	if (isRoot(z)) {
		tree->root = b;
		b->parent = NULL;
	}
	else if (z_parent->LChild == z) {
		z_parent->LChild = b;
		b->parent = z->parent;
	}
	else {
		z_parent->RChild = b;
		b->parent = z->parent;
	}

	a->LChild = T0;
	T0->parent = a;
	a->RChild = T1;
	T1->parent = a;
	a->height = _max(T0->height, T1->height) + 1;

	c->LChild = T2;
	T2->parent = c;
	c->RChild = T3;
	T3->parent = c;
	c->height = _max(T2->height, T3->height) + 1;

	b->LChild = a;
	a->parent = b;
	b->RChild = c;
	c->parent = b;
	b->height = _max(a->height, c->height) + 1;

	return b;
}

void searchAndRepairAfterRemoval(treeNode *w) {
	treeNode *z = w;
	treeNode *y, *x, *b;

	while (heightUpdateAndBalanceCheck(z)) {
		if (isRoot(z))
			return;
		z = z->parent;
	}
	if (z->LChild->height > z->RChild->height)
		y = z->LChild;
	else
		y = z->RChild;

	if (y->LChild->height > y->RChild->height)
		x = y->LChild;
	else if (y->LChild->height < y->RChild->height)
		x = y->RChild;
	else if (z->LChild == y)
		x = y->LChild;
	else if (z->RChild == y)
		x = y->RChild;

	b = restructure(x);
	searchAndRepairAfterRemoval(b);
	return;
}


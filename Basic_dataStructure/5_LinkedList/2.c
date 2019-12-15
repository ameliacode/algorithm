#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct listNode{
	struct listNode *next;
	int coef;
	int exp;
}Node;


void appendTerm(Node* k, int c, int e)
{
	Node *t;
	t=(Node*)malloc(sizeof(Node));
	t->coef=c;
	t->exp=e;
	t->next=NULL;
	k->next=t;
	k=t;
	return;
}

Node* addPoly(Node *x, Node *y)
{
	Node *i, *j;
	Node *result;
	Node *k;
	int sum=1;

	result=(Node*)malloc(sizeof(Node));
	result->next=NULL;
	result->coef=0;
	result->exp=0;
	i=x->next;
	j=y->next;
	k=result;

	while((i!=NULL)&&(j!=NULL))
	{
		if(i->exp > j->exp){
			appendTerm(k, i->coef, i->exp);
			i=i->next;
			k=k->next;
		}
		else if(i->exp < j->exp){
			appendTerm(k,j->coef,j->exp);
			j=j->next;
			k=k->next;
		}
		else{
			sum=i->coef+j->coef;
			if(sum!=0)
			{
				appendTerm(k,sum,i->exp);
				k=k->next;
			}
			i=i->next;
			j=j->next;
			//sum=0;
		}
	}
	while(i!=NULL){
		appendTerm(k,i->coef,i->exp);
		i=i->next;
		k=k->next;
	}
	while(j!=NULL){
		appendTerm(k,j->coef,j->exp);
		j=j->next;
		k=k->next;
	}
	return result;
}

int main(void)
{
	int N;
	int coef, exp;
	Node *a,*b,*c;
	Node *temp;
	Node *a_tmp, *b_tmp;
	a=(Node*)malloc(sizeof(Node));
	b=(Node*)malloc(sizeof(Node));
	c=(Node*)malloc(sizeof(Node));
	
	//a
	a_tmp = a;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		scanf("%d %d", &coef, &exp);
		appendTerm(a_tmp,coef,exp);
		a_tmp=a_tmp->next;
	}

	//b
	b_tmp=b;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		scanf("%d %d", &coef, &exp);
		appendTerm(b_tmp,coef,exp);
		b_tmp=b_tmp->next;
	}

	c=addPoly(a,b);
	temp=c->next;

	while(temp!=NULL)
	{
		printf(" %d %d",temp->coef, temp->exp);
		temp=temp->next;
	}
	return 0;
}

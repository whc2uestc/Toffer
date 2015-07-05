#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
	int element;
	ListNode *Next;
}ListNode;

static ListNode* allocNode(int element){
	ListNode *pNode = (ListNode*)malloc(sizeof(ListNode));
	if(NULL != pNode){
		pNode->element = element;
		pNode->Next = NULL;
	}
	return pNode;
}


static void push(ListNode **pFirst,int element){
	if(NULL == pFirst)
		return;
	if(NULL == *pFirst){
		*pFirst = allocNode(element);
		return ;
	}
	ListNode *pNode = *pFirst;
	while(pNode->Next){
		pNode = pNode->Next;
	}
	pNode->Next = allocNode(element);
}

static void freeNode(ListNode *pFirst){
	ListNode *pNode = NULL;
	while(pFirst){
		pNode = pFirst->Next;
		free(pFirst);
		pFirst = pNode;
	}
}
static ListNode* reverList(ListNode *pFirst){
	if(NULL == pFirst)
		return NULL;
	ListNode *pAhead = pFirst->Next;
	ListNode *pBhand = pFirst;
	ListNode *pNode = NULL;
	pBhand->Next = NULL;
	while(pAhead){
		pNode = pAhead;
		pAhead = pAhead->Next;
		pNode->Next = pBhand;
		pBhand = pNode;
	}
	return pBhand;
}

static void printList(const ListNode *pFirst){
	if(pFirst == NULL){
		printf("NULL\n");
		return;
	}
	printf("%d",pFirst->element);
	pFirst = pFirst->Next;
	while(pFirst){
		printf(" %d",pFirst->element);
		pFirst = pFirst->Next;
	}
	printf("\n");
}


int main16(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(0 == n){
			printf("NULL\n");
			continue;
		}
		ListNode *pFirst = NULL;
		int i = 0;
		int element;
		while(i < n){
			scanf("%d",&element);
			push(&pFirst,element);
			i++;
		}
		pFirst = reverList(pFirst);
		printList(pFirst);
		freeNode(pFirst);
		pFirst = NULL;
	}

	return 0;
}
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

ListNode* mergeList(ListNode *pFirst1, ListNode *pFirst2){
	if(NULL == pFirst1 && NULL == pFirst2)
		return NULL;
	if(NULL == pFirst1 && NULL != pFirst2)
		return pFirst2;
	if(NULL != pFirst1 && NULL == pFirst2)
		return pFirst1;
	ListNode *pFirst = NULL;
	ListNode *pNode = NULL;
	if(pFirst1->element > pFirst2->element){
		pFirst = pFirst2;
		pFirst2 = pFirst2->Next;
	}
	else{
		pFirst = pFirst1;
		pFirst1 = pFirst1->Next;
	}
	pNode = pFirst;
	while(NULL != pFirst1 && NULL != pFirst2){
		if(pFirst1->element > pFirst2->element){
			pNode->Next = pFirst2;
			pFirst2 = pFirst2->Next;
		}
		else{
			pNode->Next = pFirst1;
			pFirst1 = pFirst1->Next;
		}
		pNode = pNode->Next;
	}
	if(NULL == pFirst1)
		pNode->Next = pFirst2;
	else
		pNode->Next = pFirst1;
	return pFirst;
}

int main17(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		ListNode *pFirst1 = NULL,*pFirst2 = NULL;
		int i = 0;
		int element;
		while(i < n){
			scanf("%d",&element);
			push(&pFirst1,element);
			i ++;
		}
		i = 0;
		while(i < m){
			scanf("%d",&element);
			push(&pFirst2,element);
			i ++;
		}
		ListNode *pFirst = mergeList(pFirst1,pFirst2);
		printList(pFirst);
		freeNode(pFirst);
	}

	return NULL;
}



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

int main15(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		ListNode *pFirst = NULL;
		int flag = 0;
		int i = 0;
		while(i < n){
			int element;
			scanf("%d",&element);
			push(&pFirst,element);
			i++;
		}
		if(k == 0){
			printf("NULL\n");
			free(pFirst);
			pFirst = NULL;
			continue;
		}
		ListNode *pPre = pFirst,*pPost = pFirst;
		for(i=0; i<k; i++){
			if(NULL == pPre){
				printf("NULL\n");
				flag = 1;
				break;
			}
			pPre = pPre->Next;
		}
		while(pPre != NULL){
			pPre = pPre->Next;
			pPost = pPost->Next;
		}
		if(!flag)
			printf("%d\n",pPost->element);

		free(pFirst);
		pFirst = NULL;
	}
	return 0;
}
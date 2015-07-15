#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
typedef struct TreeNode{
	int element;
	struct TreeNode *pLeft,*pRight;
}Node;

int find(int arr[],int x,int begin,int end){
	while(begin <= end){
		if(arr[begin] == x)
			return begin;
		begin ++;
	}
}



void postSerch(Node *pTree){
	if(pTree == NULL)
		return;
	postSerch(pTree->pLeft);
	postSerch(pTree->pRight);
	printf("%d ",pTree->element);
}

int main6(){
	
	BEGIN:int n;
	while(scanf("%d",&n)!=EOF){
	int preNum[1000];
	int inNum[1000];
	char flag[1000] = {0};
	int i = 0;
	while(i < n){
		scanf("%d",&preNum[i]);
		i ++;
	}
	i = 0;
	while(i < n){
		scanf("%d",&inNum[i]);
		i ++;
	}
	int preIndex,inIndex0,inIndex1;
	Node *pFirst = NULL; 
	pFirst = (Node*)malloc(sizeof(Node));
	pFirst->element = preNum[0];
	pFirst->pLeft = NULL;
	pFirst->pRight = NULL;
	stack<int> pStack;
	stack<Node*> pStackNode;
	inIndex0 = find(inNum,preNum[0],0,n-1);
	flag[inIndex0] = 1;
	pStack.push(inIndex0);
	pStackNode.push(pFirst);
	Node *pNode,*pCurr = pFirst;
	for(i=1; i<n; i++){
		inIndex1 = find(inNum,preNum[i],0,n-1);
		flag[inIndex1] = 1;
		if(inIndex1<inIndex0){//◊Û
			pCurr = pStackNode.top();
			pNode = (Node*)malloc(sizeof(Node));
			pNode->element = preNum[i];
			pNode->pLeft = NULL;
			pNode->pRight = NULL;
			pCurr->pLeft = pNode;
		}
		else{//”“
			
			while(!pStack.empty() && pStack.top()<inIndex1){
				preIndex = pStack.top();
				pStack.pop();
				pCurr = pStackNode.top();
				pStackNode.pop();
			}
			int index;
			for(index=0;index<preIndex;index++){
				if(flag[index]==0){
					printf("No\n");
					goto BEGIN;
				}

			}
			pNode = (Node*)malloc(sizeof(Node));
			pNode->element = preNum[i];
			pNode->pLeft = NULL;
			pNode->pRight = NULL;
			pCurr->pRight = pNode;
		}
		pStack.push(inIndex1);
		pStackNode.push(pNode);
		inIndex0 = inIndex1;
	}
	postSerch(pFirst);
	printf("\n");
	}
	return 0;
}
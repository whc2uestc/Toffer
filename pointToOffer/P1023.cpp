#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct BTreeNode{
	int index;
	int element;
	struct BTreeNode *pLeft;
	struct BTreeNode *pRight;
}BTreeNode;

queue<BTreeNode*> pQueue;
static BTreeNode* allocNode(int element,int index){
	BTreeNode *pNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	if(NULL != pNode){
		pNode->element = element;
		pNode->index = index;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

static bool insert2(BTreeNode *pRoot,int index,int element1,int element2,int index1,int index2){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pLeft = allocNode(element1,index1);
		pRoot->pRight = allocNode(element2,index2);
	}
	if(insert2(pRoot->pLeft,index,element1,element2,index1,index2))
		return true;
	return insert2(pRoot->pRight,index,element1,element2,index1,index2);
}

static bool insertLeft(BTreeNode *pRoot,int index,int element1,int index1){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pLeft = allocNode(element1,index1);
	}
	if(insertLeft(pRoot->pLeft,index,element1,index1))
		return true;
	return insertLeft(pRoot->pRight,index,element1,index1);
}

static bool insertRight(BTreeNode *pRoot,int index,int element2,int index2){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pRight = allocNode(element2,index2);
	}
	if(insertRight(pRoot->pLeft,index,element2,index2))
		return true;
	return insertRight(pRoot->pRight,index,element2,index2);
}

static void printTree(const BTreeNode *pRoot){
	if(NULL == pRoot)
		return;
	printf("%d",pRoot->element);
	if(NULL != pRoot->pLeft)
		pQueue.push(pRoot->pLeft);
	if(NULL != pRoot->pRight)
		pQueue.push(pRoot->pRight);
	BTreeNode *pNode = NULL;
	while(!pQueue.empty()){
		pNode = pQueue.front();
		printf(" %d",pNode->element);
		if(NULL != pNode->pLeft)
			pQueue.push(pNode->pLeft);
		if(NULL != pNode->pRight)
			pQueue.push(pNode->pRight);
		pQueue.pop();
	}
	printf("\n");
}

static void freeTree(BTreeNode *pRoot){
	if(NULL == pRoot)
		return ;
	freeTree(pRoot->pLeft);
	freeTree(pRoot->pRight);
	free(pRoot);
}

int main23(){
	int n;
	while(scanf("%d",&n)!=EOF && n>=1 && n<=1000 ){
		int i = 0;
		int num[1000];
		while(i < n){
			scanf("%d",&num[i++]);
		}
		BTreeNode *pRoot = allocNode(num[0],0);
		i = 0;
		while(i < n){
			char ci;
			int sub[2];
			scanf("\n%c",&ci);
			if(ci == 'd'){
				scanf("%d %d",&sub[0],&sub[1]);
				insert2(pRoot,i,num[sub[0]-1],num[sub[1]-1],sub[0]-1,sub[1]-1);
			}
			else if(ci == 'l'){
				scanf("%d",&sub[0]);
				insertLeft(pRoot,i,num[sub[0]-1],sub[0]-1);
			}
			else if(ci == 'r'){
				scanf("%d",&sub[0]);
				insertRight(pRoot,i,num[sub[0]-1],sub[0]-1);
			}
			i ++;
		}

		printTree(pRoot);
		freeTree(pRoot);

	}

	return 0;
}
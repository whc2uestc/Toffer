#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode{
	int index;
	int element;
	struct BinaryTreeNode *pLeft;
	struct BinaryTreeNode *pRight;
}BTreeNode;

BTreeNode*  allocNode(int element,int index){
	BTreeNode *pNode = NULL;
	pNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	if(NULL != pNode){
		pNode->index = index;
		pNode->element = element;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

bool insertLeft(BTreeNode *pRoot,int index,int element1,int index1){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pLeft = allocNode(element1,index1);
		return true;
	}
	if(insertLeft(pRoot->pLeft,index,element1,index1))
		return true;
	if(insertLeft(pRoot->pRight,index,element1,index1))
		return true;
	return false;
}


bool insertRight(BTreeNode *pRoot,int index,int element2,int index2){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pRight = allocNode(element2,index2);
		return true;
	}
	if(insertRight(pRoot->pLeft,index,element2,index2))
		return true;
	if(insertRight(pRoot->pRight,index,element2,index2))
		return true;
	return false;
}

bool insert(BTreeNode *pRoot,int index,int element1,int element2,int index1,int index2){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->pLeft = allocNode(element1,index1);
		pRoot->pRight = allocNode(element2,index2);
		return true;
	}
	if(insert(pRoot->pLeft,index,element1,element2,index1,index2))
		return true;
	if(insert(pRoot->pRight,index,element1,element2,index1,index2))
		return true;
	return false;
}

void imageTree(BTreeNode *pRoot){
	if(NULL == pRoot)
		return;
	BTreeNode *pLeft = pRoot->pLeft;
	BTreeNode *pRight = pRoot->pRight;
	pRoot->pLeft = pRight;
	pRoot->pRight = pLeft;
	imageTree(pRight);
	imageTree(pLeft);
}

void _preSerch(BTreeNode *pRoot){
	if(NULL == pRoot)
		return;
	printf(" %d",pRoot->element);
	_preSerch(pRoot->pLeft);
	_preSerch(pRoot->pRight);
}

void preSerch(BTreeNode *pRoot){
	if(NULL == pRoot)
		return;
	printf("%d",pRoot->element);
	_preSerch(pRoot->pLeft);
	_preSerch(pRoot->pRight);
	printf("\n");
}


void freeTree(BTreeNode *pRoot){
	if(pRoot == NULL)
		return;
	freeTree(pRoot->pLeft);
	freeTree(pRoot->pRight);
	free(pRoot);
}

int main19(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(0 == n){
			printf("NULL\n");
			continue;
		}
		int element[1000];
		int i = 0;
		while(i < n){
			scanf("%d",&element[i]);
			i ++;
		}

		BTreeNode *pRoot = allocNode(element[0],0);
		char flag;
		int sub[2];
		for(i=0; i<n; i++){
			getchar();
			scanf("%c",&flag);
			if(flag == 'd'){
				scanf("%d %d",&sub[0],&sub[1]);
				insert(pRoot,i,element[sub[0]-1],element[sub[1]-1],sub[0]-1,sub[1]-1);
			}else if(flag == 'l'){
				scanf("%d",&sub[0]);
				insertLeft(pRoot,i,element[sub[0]-1],sub[0]-1);
			}else if(flag == 'r'){
				scanf("%d",&sub[0]);
				insertRight(pRoot,i,element[sub[0]-1],sub[0]-1);
			}
		}
		imageTree(pRoot);
		preSerch(pRoot);
		freeTree(pRoot);
	}

	return 0;
}
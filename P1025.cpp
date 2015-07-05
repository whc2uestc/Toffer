#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;
typedef struct BinaryTreeNode{
	int index;
	int element;
	struct BinaryTreeNode *pLeft,*pRight;
}BTreeNode;

static BTreeNode* allocNode(int index,int element){
	BTreeNode *pNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	if(NULL != pNode){
		pNode->index = index;
		pNode->element = element;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

bool insert(BTreeNode *pRoot,int index, int element,int sub[]){
	if(NULL == pRoot)
		return false;
	if(pRoot->index == index){
		pRoot->element = element;
		if(-1 != sub[0])
			pRoot->pLeft = allocNode(sub[0],0);
		if(-1 != sub[1])
			pRoot->pRight = allocNode(sub[1],1);
		return true;
	}
	if(insert(pRoot->pLeft,index,element,sub))
		return true;
	return insert(pRoot->pRight,index,element,sub);
}
deque<int> pDeque;
deque<int> pStack;
void findPath(BTreeNode *pRoot,int sum){
	if(sum < 0)
		return ;
	if(NULL == pRoot && 0 == sum){
		pStack = pDeque;
		while(!pDeque.size()){
			printf("%d ",pDeque.front());
			pDeque.pop_front();
		}
	}
	if(NULL == pRoot){
		return;
	}
	pDeque.push_back(pRoot->element);
	sum -= pRoot->element;
	
}


int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF && n>=1 && n<=10000){
		int i = 0,element;
		int sub[2] = {0};
		BTreeNode *pRoot = allocNode(1,0);
		while(i < n){
			scanf("%d %d %d",&element,&sub[0],&sub[1]);
			insert(pRoot,i+1,element,sub);
			i ++;
		}


	}

	return 0;
}
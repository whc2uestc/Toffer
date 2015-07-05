#include <stdio.h>
#include <stdlib.h>
typedef struct _TreeNode{
	int element;
	int index;
	struct _TreeNode *pLeft;
	struct _TreeNode *pRight;
}TreeNode;


static TreeNode* allocNode(int element,int index){
	TreeNode *pNode = (TreeNode*)malloc(sizeof(TreeNode));
	if(pNode != NULL){
		pNode->element = element;
		pNode->index = index;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

static bool insert1(TreeNode *pRoot,int index,int element1,int index1){
		if(pRoot == NULL)
			return false;
		if(pRoot->index == index){
			pRoot->pLeft = allocNode(element1,index1);
			return true;
		}
		if(insert1(pRoot->pLeft,index,element1,index1))
			return true;
		if(insert1(pRoot->pRight,index,element1,index1))
			return true;
		return false;
}

static bool insert(TreeNode *pRoot,int index,int element1,int element2,int index1,int index2){
		if(pRoot == NULL)
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
bool judge(TreeNode *pRootA, TreeNode *pRootB){
	if(pRootB == false)
		return true;
	if(pRootA == NULL)
		return false;
	if(pRootA->element == pRootB->element){
		if(judge(pRootA->pLeft,pRootB->pLeft)){
			return judge(pRootA->pRight,pRootB->pRight);
		}
		else
			return false;
	}
	return false;
}

bool haveSub(TreeNode *pRootA,TreeNode *pRootB){
	if(pRootA == NULL)
		return false;

	if(pRootA->element == pRootB->element){
		if(judge(pRootA,pRootB))
			return true;
	}
	if(haveSub(pRootA->pLeft,pRootB))
		return true;
	if(haveSub(pRootA->pRight,pRootB))
		return true;
	return false;
}

int main18(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		TreeNode *pRootA = NULL;
		TreeNode *pRootB = NULL;
		int element[1000] = {0};
		int i = 0;
		while(i < n){
			scanf("%d",&element[i]);
			i ++;
		}
		pRootA = allocNode(element[0],0);
		for(i=0; i<n; i++){
			int num;
			int sub[2];
			scanf("%d",&num);
			if(num == 0)
				continue;
			if(num == 1){
				scanf("%d",&sub[0]);
				insert1(pRootA,i,element[sub[0]-1],sub[0]-1);
			}
			else
			{
				scanf("%d %d",&sub[0],&sub[1]);
				insert(pRootA,i,element[sub[0]-1],element[sub[1]-1],sub[0]-1,sub[1]-1);
			}
		}
		if(m == 0){
			printf("NO\n");
			continue;
		}
		i = 0;
		while(i < m){
			scanf("%d",&element[i]);
			i ++;
		}
		pRootB = allocNode(element[0],0);
		for(i=0; i<m; i++){
			int num;
			int sub[2];
			scanf("%d",&num);
			if(num == 0)
				continue;
			if(num == 1){
				scanf("%d",&sub[0]);
				insert1(pRootB,i,element[sub[0]-1],sub[0]-1);
			}
			else
			{
				scanf("%d %d",&sub[0],&sub[1]);
				insert(pRootB,i,element[sub[0]-1],element[sub[1]-1],sub[0]-1,sub[1]-1);
			}
		}
		if(haveSub(pRootA,pRootB)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}

	}



	return 0;
}
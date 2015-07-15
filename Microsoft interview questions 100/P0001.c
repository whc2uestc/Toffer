/*
 * 1. 把二元查找树转变成排序的双向链表
 * 输入一棵二元查找树，将该转换成个排序的双向链表。
 * 要求不能创建任何新的结点，只调整指针方向。 
*/

struct BSTreeNode{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};

void transfrom(BSTreeNode *pRoot,BSTreeNode **pList){
	if(NULL == *pRoot)
		return ;
	transfrom(pRoot->m_pLeft,pList);
	if(NULL == *pList){
		*pList = pRoot;
	}
	else{
		pRoot->m_pLeft = *pList;
		*pList->m_pRight = pRoot;
	}
	transfrom(pRoot->m_pRight,pList);
} 

BSTreeNode* transformFromTreeToList(BSTreeNode *pRoot){
	if(NULL == pRoot)
		return NULL;
	BSTreeNode *pList = NULL;
	transfrom(pRoot,&pList);
	pList->m_pRight = NULL;
	while(pList->m_pLeft){
		pList = pList->m_pLeft;
	}
	return pList;
}
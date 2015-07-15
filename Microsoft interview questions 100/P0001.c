/*
 * 1. �Ѷ�Ԫ������ת��������˫������
 * ����һ�ö�Ԫ������������ת���ɸ������˫������
 * Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ�뷽�� 
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
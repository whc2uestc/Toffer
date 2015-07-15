
/*4. �ڶ�Ԫ�����ҳ���Ϊĳһֵ������·������
��Ŀ������һ�������Ϳö�Ԫ����
�����ĸ���㿪ʼ���·���һֱ��Ҷ���������γ���·����
��ӡ����������������ȵ�����·����
*/
#include <stdio.h>
#include <deque>
using namespace std;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
}
deque<int> deque_path;
void printPath(deque<int> dq){
	while(dq.size()){
		print("%d ",dq.front());
		dq.pop_front();
	}
	printf("\n");
}
void findPath(BinaryTreeNode *pRoot,int acc,int sum){
	if(pRoot == NULL && acc == sum){
		printPath(deque_path);
	}
	else{
		acc += pRoot->m_nValue;
		if(acc > sum)
			return ;
		deque_path.push_back(pRoot->m_nValue);
	}
	findPath(pRoot->m_pLeft,acc,sum);
	findPath(pRoot->m_pRight,acc,sum)
	deque_path.pop_back(pRoot->m_nValue);
}


/*4. 在二元树中找出和为某一值的所有路径（）
题目：输入一个整数和棵二元树。
从树的根结点开始往下访问一直到叶所经过有形成条路径。
打印出和与输入整数相等的所有路径。
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

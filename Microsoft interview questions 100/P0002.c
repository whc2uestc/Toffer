/* 2. ��ư��� min������ջ
 * ����ջ�����ݽṹ��Ҫ�����һ�� min�������ܹ��õ�ջ����СԪ�ء�
 * Ҫ���� min��push�Լ�pop��ʱ�临�Ӷȶ��� O(1)��
*/

#include <stack>
using namespace std;

class MinStack{
public:	
	void pop();
	void push(int element);
	int min();
private:
	stack<int> stack_data;
	stack<int> stack_min;
}

void MinStack::pop(){
	stack_data.pop();
	stack_min.pop();
}

void push(int element){
	stack_data.push(element);
	if(!stack_min.size())
		stack_min.push(element);
	else{
		if(stack_min.top() > element)
			stack_min.push(element);
		else
			stack_min.push(stack_min.top());
	}
}

int min(){
	return stack_min.top();
}
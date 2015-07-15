/* 2. 设计包含 min函数的栈
 * 定义栈的数据结构，要求添加一个 min函数，能够得到栈的最小元素。
 * 要求函数 min、push以及pop的时间复杂度都是 O(1)。
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
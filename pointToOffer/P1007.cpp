#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

stack<int> pStack0;
stack<int> pStack1;
static void push(int element){
	pStack0.push(element);
}

static int pop(){
	if(pStack1.empty() && pStack0.empty())
		return -1;
	if(pStack1.empty()){
		while(!pStack0.empty()){
			pStack1.push(pStack0.top());
			pStack0.pop();
		}
	}
	int out = pStack1.top();
	pStack1.pop();
	return out;
}

int main7(){
	int n;
	scanf("%d",&n);
	int i = 0;
	while(i<n){
		char action[10] = {0};
		int num;
		scanf("%s",action);
		if(strstr(action,"PUSH")){
			scanf("%d",&num);
			push(num);
		}
		else
			printf("%d\n",pop());
		i ++;
	}
	return 0;
}
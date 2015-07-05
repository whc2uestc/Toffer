#include <stdio.h>
#include <stack>
#include <stdlib.h>
using namespace std;

int main22(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		int num[100000] = {0};
		int i = 0;
		while(i < n){
			scanf("%d",&num[i++]);
		}
		stack<int> pStack;
		i = 0;
		int j = 0;
		int flag = 0;
		while(i < n){
			int data;
			i ++;
			scanf("%d",&data);
			if(flag)
				continue;
			if(!pStack.empty() && pStack.top() == data && !flag){
				pStack.pop();
				continue;
			}

			while(j<n && data != num[j] && !flag){
				pStack.push(num[j]);
				j ++;
			}
			if(j == n){
				flag = 1;
				continue;
			}
			else
				j ++;
			
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");

	}

	return 0;
}
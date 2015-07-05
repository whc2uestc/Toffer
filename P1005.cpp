#include <stdio.h>

static int num[1000001];

int main5(){
	int i=0;
	while(scanf("%d",&num[i])!=EOF && num[i]!=-1){
		i++;
	}
	int j;
	for(j=i-1;j>=0;j--)
		printf("%d\n",num[j]);
	return 0;
}


/*#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;

int main(){
	stack<int> pStack;
	while(1){
		int num;
		cin>>num;
		if(num == -1)
			break;
		pStack.push(num);
	}
	while(!pStack.empty){
		cout<<pStack.top()<<endl;
		pStack.pop();
	}

	return 0;
}*/
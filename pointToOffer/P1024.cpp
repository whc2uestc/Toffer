#include <stdio.h>

bool judgeSearchTree(int num[],int begin,int end){
	int i;
	if(begin == end)
		return true;
	for(i=begin;i<end;i++){
		if(num[i]>num[end])
			break;
	}
	if(i > begin){
		if(!judgeSearchTree(num,begin,i-1))
			return false;
	}
	if(i == end)
		return true;
	begin = i;
	for(;i<end;i++){
		if(num[i]<num[end])
			return false;
	}
	return judgeSearchTree(num,begin,i-1);
}

int main24(){
	int n;
	while(scanf("%d",&n)!=EOF && n>=1 && n<=10000){
		int i = 0;
		int num[10000];
		while(i < n){
			scanf("%d",&num[i++]);
		}
		if(judgeSearchTree(num,0,n-1))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
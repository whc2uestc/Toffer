#include <stdio.h>
static int num[1000000];

int main8(){
	int n;

	while(scanf("%d",&n)!=EOF){
		int i = 0;
		
		while(i < n){
			scanf("%d",&num[i]);
			i ++;
		}
		if(n==0)
			continue;
		
		int begin = 0,end = n-1;
		if(num[end]>num[begin]){
			printf("%d\n",num[begin]);
			continue;
		}
		int middle = (begin+end)/2;
		while(begin < end-1){
			while(num[middle] > num[begin] && begin < end-1){
				begin = middle;
				middle = (begin+end)/2;
			}
			if(begin >= end-1)
				break;
			end = middle;
			middle = (begin+end)/2;
			while(num[middle] < num[begin] && begin < end-1){
				end = middle;
				middle = (begin+end)/2;
			}
		}
		printf("%d\n",num[end]);
		
	}
	return 0;
}
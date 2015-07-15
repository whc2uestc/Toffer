#include <stdio.h>

static int num[100000];

void change(int begin,int end){
	while(begin < end){
		while(begin<end){
			if(num[begin]&1)
				begin ++;
			else
				break;
		}
		while(begin<end){
			if(num[end]&1)
				break;
			else
				end --;
		}
		if(begin == end)
			return;
		else{
			int temp = num[end];
			num[end] = num[begin];
			num[begin] = temp;
			begin ++;
			end --;
		}
	}

}


int main14(){
	int n;
	while(scanf("%d",&n)!=EOF && n>0){
		int i = 0;
		while(i < n){
			scanf("%d",&num[i]);
			i ++;
		}

		change(0,n-1);
		printf("%d",num[0]);
		for(i=1; i<n; i++){
			printf(" %d",num[i]);
		}
	}
	return 0;
}
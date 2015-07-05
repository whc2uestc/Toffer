#include <stdio.h>

int main10(){

	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++){
		int num;
		scanf("%d",&num);

		int j;
		int out = 0;
		for(j=0; j<32; j++){
			if(num & (1<<j))
				out ++;
		}
		printf("%d\n",out);
	}


	return 0;
}
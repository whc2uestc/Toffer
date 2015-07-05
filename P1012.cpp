#include <stdio.h>


int main12(){

	int n;
	scanf("%d",&n);

	int max = 0;
	int i;
	for(i=0; i<n; i++){
		max = max*10 + 9;
	}
	for(i=1; i<=max; i++)
		printf("%d\n",i);

	return 0;
}
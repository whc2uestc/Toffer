#include <stdio.h>

long long step(int n){
	if(n == 1)
		return 1;
	return 2*step(n-1);
}

int main9b(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n < 0) 
			continue;
		printf("%lld\n",step(n));
	}
	return 0;
}
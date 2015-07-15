#include <stdio.h>

long long fibo[100];

long long fibonacci(int n){
	if(n<=1)
		return n;
	if(fibo[n]!=0)
		return fibo[n];
	fibo[n] = fibonacci(n-1)+fibonacci(n-2);
	return fibo[n];
}

int main9(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",fibonacci(n));
	}

	return 0;
}
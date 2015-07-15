#include <stdio.h>

int main9c(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<1) continue;
		if(n==1){
			printf("1\n");
			continue;
		}
		if(n==2){
			printf("2\n");
			continue;
		}
		long long f0 = 1;
		long long f1 = 2;
		int i;
		for(i = 3; i<=n; i++){
			long long f2 = f0 + f1;
			f0 = f1;
			f1 = f2;
		}
		printf("%lld\n",f1);
	}

	return 0;
}
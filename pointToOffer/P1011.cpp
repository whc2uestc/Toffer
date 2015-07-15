#include <stdio.h>

int main11(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for(cnt=0; cnt<n; cnt ++){
		double dou;
		int num;
		scanf("%lf %d",&dou,&num);
		int exp;
		if(num<0){
			exp = -num;
			if(dou-0.0 < 0.0000001 && dou - 0.0 > -0.0000001){
				printf("INF\n");
				continue;
			}
		}
		else 
			exp = num;
		int i;
		double out = 1.0;
		for(i=0; i<exp; i++)
			out *= dou;
		if(num < 0)
			out = 1/out;
		printf("%.2ef\n",out);
	}


	return 0;
}
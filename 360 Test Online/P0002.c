#include <stdio.h>
#include <string.h>
struct Relation{
	int to_other;
	int by_other;
};
static struct Relation count[100001] = {{0,0}};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,i;
		scanf("%d %d",&n,&m);
		memset(count,0,sizeof(struct Relation)*100001);
		int a,b;
		while(m--){
			scanf("%d %d",&a,&b);
			if(a != b){
				count[a].to_other ++;
				count[b].by_other ++;
			}
		}
		int res[100001] = {0};
		int res_cnt = 0;
		for(i=1; i<=n; i++){
			if(count[i].by_other == n-1 && count[i].to_other == 0){
				res[res_cnt] = i;
				res_cnt ++;
			}
		}
		printf("%d\n",res_cnt);
		if(0 == res_cnt)
			printf("\n");
		else{
			printf("%d",res[0]);
			for(i=1; i<res_cnt; i++)
				printf(" %d",res[i]);
			printf("\n");
		}
	}

	return 0;
}

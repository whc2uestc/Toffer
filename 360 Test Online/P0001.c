#include <stdio.h>
#include <string.h>

struct chr{
	int cnt;
	int index;
};

int main(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		int i = 1;
		struct chr temp[256]={{0,0}};
		char str[10000] = {0};
		scanf("%s",str);
		int len = strlen(str);
		for(i=0; i<len; i++){
			temp[str[i]].cnt ++;
			temp[str[i]].index = i;
		}
		char res;
		int index = -1;
		for(i=0;i<256;i++){
			if(temp[i].cnt == 1){
				if(-1 == index){
					index = temp[i].index;
					res = (char)i;
				}
				else if(index>temp[i].index){
						index = temp[i].index;
						res = i;
				}
			}
		}
		printf("%c\n",res);
	}

	return 0;
}
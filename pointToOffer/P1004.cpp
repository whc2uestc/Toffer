/*#include <stdio.h>
#include <string.h>
char str[1000001];
char len;
void replace(int n){
	int i,j;
	for(i=len-1,j=len+n*2-1;i>=0;i--,j--){
		if(str[i] == ' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j] = '%';
		}
		else
			str[j] = str[i];
	}
}


int main(){

	gets(str);
	len = strlen(str);
	int i;
	int cnt = 0;
	for(i=0;i<len;i++){
		if(str[i] == ' ')
			cnt ++;
	}
	replace(cnt);
	puts(str);
	return 0;
}*/

#include <stdio.h>
#include <string.h>
 char str[1000001];
int main2(void){
    
    int len;
    int new_len;
    int i;
    int cnt;
 
    gets (str);
    len = strlen(str);
    cnt = 0;
    for (i=0; i<len; ++i){
        if (str[i] == ' ')
            cnt ++;
    }
    new_len = len + 2 * cnt;
    str[new_len] = '\0';
    --len;
    --new_len;
	int j;
    for(i=len,j=new_len;i>=0;i--,j--){
		if(str[i] == ' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j] = '%';
		}
		else
			str[j] = str[i];
	}
    puts (str);
 
    return 0;
}
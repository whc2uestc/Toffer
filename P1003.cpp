#include <stdio.h>
int N,M;
int k;
static int num[100][100];
int flag;
int find(int j,int begin,int end){
	int middle = (begin+end)/2;
	while(begin<end){
		if(num[middle][j] == k){
			flag=1;
			return middle;
		}
		if(num[middle][j]>k){
			end = middle-1;
		}
		else{
			begin = middle+1;
		}	
		middle = (begin+end)/2;
	}
	return begin;
}


int findRow(int arr[],int begin,int end){
	int middle = (begin+end)/2;
	while(begin!=end){
		if(arr[middle] == k){
			return middle;
		}
		if(arr[middle]>k){
			end = middle-1;
		}
		else{
			begin = middle+1;
		}	
	}
	middle = (begin+end)/2;
	return begin;
}

int main1(){
	scanf("%d %d",&N,&M);
	scanf("%d",&k);

	int i,j;
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			scanf("%d",&num[i][j]);

	int row,col=M-1;
	if(k>num[N-1][M-1] && k<num[0][0])
		printf("false");
	for(j=M-1; j>=0; j--){
		if(k<num[0][j]){
			col --;
			continue;
		}
		else{
			row = find(j,0,N-1);
			break;
		}
	}
	
	int col0 = findRow(num[row],0,col);
		
	if(k==num[row][col0])
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
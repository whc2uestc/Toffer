/*3. �������������
����һ���������飬������Ҳ����
������ ������һ�������������ӣ�ÿ���к͡�
������������ĺ����ֵ��Ҫʱ�临�Ӷ�Ϊ O(n)��
*/

int getMaxSum(int *arr,int n){
	int i;
	int max_sum = 0;
	int sum = 0;
	for(i=0; i<n; i++){
		if(sum+arr[i] < sum){
			if(sum > max_sum)
				max_sum = sum;
			if(sum+arr[i] > 0)
				sum += arr[i];
			else
				sum = 0;
		}
		else{
			sum += arr[i];
		}
	}
	if(sum > max_sum)
		max_sum = sum;
	return max_sum;
	
}
/*3. 求子数组的最大和
输入一个整形数组，里有正也负。
数组中 连续的一个或多整数组成子，每都有和。
求所有子数组的和最大值。要时间复杂度为 O(n)。
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
//������Ӵ�
// dp[j] = max(dp[i])+1 ����i<j��a[j]>a[i] 
//  ��������κ�����С����ôdp[j]=1
//  https://blog.csdn.net/tigerisland45/article/details/72850070
#include<stdio.h>
#include<stdlib.h> 
int main(){
	int n;
	scanf("%d",&n);
	int* arr = (int *)malloc(sizeof(int)*n);
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
	
	
	int* dp =(int *)malloc(sizeof(int)*n);

	dp[0] = 1;
	
	for(int i=1;i<n;i++){
		dp[i] = 1;
		int flag = 0;//flag��������¼�Ƿ��Ѿ����¹��� 
		for(int j =0 ; j<i;j++){
			//ǰ�ᣬ���Ǹ���С	
			if(arr[j] < arr[i]){
				
				if(dp[i] <= dp[j]){
					dp[i] = dp[j];
					flag = 1;
				}	
					
			}
		}
		//���¹�֮����ԭ���Ļ�����+1 
		if(flag)
			dp[i] = dp[i]+1;
		
	}
	
	int max = dp[0];
	for(int i=0; i<n ;i++){
		//printf("%d ",dp[i]);
		if(max<dp[i])
			max = dp[i];
	}
	
	
	printf("%d",max);
	
	
	
	return 0;
}

 

 

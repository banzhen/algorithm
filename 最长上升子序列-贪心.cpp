#include<stdio.h>
#include<stdlib.h>

int bin_search(int dp[],int start, int end,int num){
	int i=start;
	int j=end;
	int mid = (i+j)/2;
	

	
	while(i<=j){
		mid = (i+j)/2;
		if(num == dp[mid])
			return mid;
		else if(num < dp[mid])
			j = mid-1;
		else
			i = mid+1;
	}
	return i;
	
}


int main(){
	printf("a");
	
	int n;
	scanf("%d",&n);
	//int* num = (int*)malloc(sizeof(int)*(n+1));
//	int *dp = (int*)malloc(sizeof(int)*(n+1));
	
	int num[100];
	int dp[100]; 
	
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	int len=1;
	dp[1] = num[0];
	
	
	
	for(int i=1;i<n;i++){
		int index = bin_search(dp,1,len,num[i]);
		if(index==1)
			dp[index] = num[i];
		else{
			if(index == len+1 ){
				dp[len+1] = num[i];
				len++;
			}else{
				if(num[i] < dp[index])
					dp[index] = num[i];	
			}
				
			
			
		}
		
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",dp[i]);
	}
	
	printf("len = %d",len);
	
	
	
	return 0;
} 

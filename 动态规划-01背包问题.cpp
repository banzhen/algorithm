


// dp[i][j] 表示第i个元素，容量为j的最大值 。  
// 如果不放进来 dp[i][j] = dp[i-1][j]
// 如果放进来  dp[i][j] = dp[i-1][j-w]+v
// dp = max{dp[i-1][j],dp[i-1][j-w]+v}
//如果 w >j 则不能放进来  dp[i-1][j]



#include<stdio.h>
#include<stdlib.h>
typedef struct Bag{
	int weight;
	int value;
}Bag;


int main(){
	
	int n ,weight;
	printf("请输入背包的数量");
	scanf("%d",&n);
	
	Bag bags[n+1];
	
	for(int i=1 ; i<n+1 ; i++){
		scanf("%d%d",&bags[i].weight,&bags[i].value);
	}
	
	printf("请输入背包的重量");
	scanf("%d",&weight);
	
	int dp[n+1][weight+1] = {0};
	
	
	
	for(int i=0;i<n+1;i++){
		for(int j=0; j<weight+1;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(bags[i].weight > j){
				dp[i][j] = dp[i-1][j];
			}else{
				int a1 = dp[i-1][j];
				int a2 = dp[i-1][j-bags[i].weight]+bags[i].value;
				int max = a1>a2?a1:a2;
				dp[i][j] = max;			
			}
		}
	}
	
	
	for(int i=0;i<n+1;i++){
		for(int j=0; j<weight+1; j++){
			printf("%4d",dp[i][j]);
		}
		printf("\n");
	}

	
	int get[n+1];
	
	
	

	return 0;
} 

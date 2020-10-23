 #include<stdio.h>
typedef struct TBag{
	int value;
	int heavy;
	double div;
}TBag;

int sort(TBag arr[],int start, int end){
	int i,j;
	i=start;
	j= end;
	//int temp = arr[start];
	TBag temp = arr[start]; 	
	
	while(i<j){
		while(i<j && arr[j].div<=temp.div )
			j--;
	
		arr[i] = arr[j];
		
		while(i<j && arr[i].div>=temp.div ) 
			i++;
		arr[j] = arr[i];
	}
	arr[i] = temp;
	return i;
		
}


int quickSort(TBag arr[], int start, int end){
	if(start<end){
		int k = sort(arr,start,end);
		quickSort(arr,start,k-1);
		quickSort(arr,k+1,end);
	}
}



int main(){
	
	TBag bags[10];
	
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&bags[i].heavy , &bags[i].value);
		bags[i].div = bags[i].value*1.0 / bags[i].heavy;
	}
	
	quickSort(bags,0,n-1);
	
	
	for(i=0;i<n;i++){
		printf("%d %d %lf\n",bags[i].heavy,bags[i].value,bags[i].div);
	}
	
	
	int heavy; //存储容量 
	scanf("%d",&heavy);
	for(i=0;i<n;i++){
		
		
		if(heavy >= bags[i].heavy){//可以全部装入 
			heavy = heavy - bags[i].heavy;
			
		}else{//不能全部装入 
			break; 
			
		}
	}
	
	int k = i;
	printf("%8s%8s \n","重量","价值");
	for(i=0;i<k;i++){
		printf("%8d%8d \n",bags[i].heavy,bags[i].value);
	}
	
	if(heavy>0 && i<n){
		printf("%8d%8.2lf \n",heavy, bags[i].value*1.0 / bags[i].heavy * heavy);		
	} 
	
	
	
	
	
	
	 
	return 0;
} 

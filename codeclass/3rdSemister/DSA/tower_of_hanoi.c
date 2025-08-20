#include<stdio.h>
void tower_of_hanoi(int n,int source,int inter,int dest){
	if(n==0){
		return 0;
	}
	tower_of_hanoi(n-1,source,inter,dest);
	printf("Move %d to %d \n",source,dest);
	tower_of_hanoi(n-1,inter,source,dest);
}
int main(){
int n;
printf("Enter the number of disk:\n");
scanf("%d",&n);
tower_of_hanoi(n,1,2,3);
return 0;
}
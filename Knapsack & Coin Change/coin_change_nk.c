#include<stdio.h>
#include<stdlib.h>

//This is similar to the Q2.a & b solution as this will run with the runtime of O(nk) 
int makechange(int denom[],int amt,int size){
int count=0,j=0;
for(int i=size-1;i>=0;i--){
while(denom[i]<=amt){
	printf("%d\t",denom[i]);
	amt=amt-denom[i];
	count++;
}
}
return count;
}


int main(){
int size=0,amount=0;
printf("Enter the number of coin denomination:\n");
scanf("%d",&size);
int denom[size];
printf("Enter the coin denomination in ascending order:");
for(int i=0;i<size;i++){
scanf("%d",&denom[i]);
}
printf("Enter the amount to calculate the change:\n");
scanf("%d",&amount);
printf("The Solution is:\n");
int count=makechange(denom,amount,size);
printf("\nNumber of coins required are:%d\n",count);
}

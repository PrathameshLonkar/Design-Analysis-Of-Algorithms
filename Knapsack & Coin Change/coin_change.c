#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Max_NUM_Change 30

int print(int change[],int size){
printf("The change are as follows:");
for(int i=0;i<size;i++){
printf("%d\t",change[i]);
}
}

int FindChange(int denom[],int amt,int size){
int Change[Max_NUM_Change],count=0,j=0;
//Here i am iteration from the last element as for part b of the question we have the coin denomination increasing exponentially hence as we are using a greedy aproach we would start with the maximum denomination first and then itterate to lower denominations
for(int i=size-1;i>=0;i--){
while(denom[i]<=amt){
	Change[j]=denom[i];
	j++;
	amt=amt-denom[i];
	count++;
}
}

print(Change,count);
}

int main(){
printf("\n------------------Start of Part Q2.1)-----------------------\n\n");
int denom[] ={1,5,10,25};
int amount=0,c=0,k=0;
int size=sizeof(denom)/sizeof(int);
printf("Enter the Amount you want change for:\n");
scanf("%d",&amount);
FindChange(denom,amount,size);

printf("\n\n-------------Start of Part Q2.b)----------------------\n\n");
printf("Insert the value of c:\n");
scanf("%d",&c);
printf("Enter the number of coins as denominations:\n");
scanf("%d",&k);
int B[k];
for(int i=1;i<=k;i++){
B[i-1]= pow(c,i);
}
int size1=sizeof(B)/sizeof(int);
FindChange(B,amount,size1);
}

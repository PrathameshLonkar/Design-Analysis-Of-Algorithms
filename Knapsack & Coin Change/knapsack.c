#include<stdio.h>
#include<stdlib.h>

void knapsack(int weights[], int values[],int items,int capacity,int table[items+1][capacity+1]){
//int table[items+1][capacity+1];

for(int i=0;i<=items+1;i++){
for(int j=0;j<capacity+1;j++){
if(j==0||i==0){
table[i][j]=0;
}
}
}
//printf("Value of capacity is :%d",capacity);
//printf("Value of items is :%d",items);

for(int j=1;j<=capacity+1;j++){
	for(int i=1;i<=items;i++){
		int new = (table[i-1][j-weights[i]]+values[i]);
		//printf("value of new is %d at i= %d, j=%d \n",new,i,j);
		int prev = table[i-1][j];
		//printf("value of prev is %d at i= %d, j=%d \n",prev,i,j);
		if(j-weights[i]>0){
			if(new>prev){
				table[i][j]=new;
			}else{
				table[i][j]=prev;
			}
		
		}else{
			table[i][j]=prev;
		}
		printf("Value in table after every itteration is %d at position i= %d, j=%d \n",table[i][j],i,j);
		
	}
}

//return table;
}


int main(){
int no_items=0, Capacity=0;

printf("Enter the number of items:\n");
scanf("%d",&no_items);

printf("Enter the Capacity of the problem");
scanf("%d",&Capacity);

int weights[no_items];
int values[no_items];
int table[no_items+1][Capacity+1];
printf("Enter the weights of the item\n");
for(int i=1;i<=no_items;i++){
scanf("%d",&weights[i]);
}

printf("Enter the values of the items\n");
for(int i=1;i<=no_items;i++){
scanf("%d",&values[i]);
}

knapsack(weights,values,no_items,Capacity,table);
printf("the optimal solution is :%d \n",table[no_items][Capacity+1]);

for(int i=0;i<=no_items+1;i++){
	for(int j=0;j<Capacity+1;j++){
		printf("%d \t",table[i][j]);
	
	}
	printf("\n");
}
}

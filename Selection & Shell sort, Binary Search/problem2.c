#include<stdlib.h>
#include<stdio.h>


int CoolSort(int A[],int Seq[],int size_arr,int seq_size){
	int k=0;
	int temp=0;//To store the temp value to be switched
	//printf("Entered CoolSort");
	for(int i=0;i<seq_size;i++){//Outer loop will run for the number of sequences present in the array
		k=Seq[i];
		//printf("Entered Outer Loop");
		for(int j=0;j<k;j++){//will run for the value each sequence
			//printf("Entered Middle Loop");
			for(int l=j;l<size_arr;l+=k){//inner loop will run with value of index incremented by the gap provided
				//printf("Entered Inner Loop");
				if(l+k<size_arr&&A[l]>A[l+k]){
				temp=A[l];
				A[l]=A[l+k];
				A[l+k]=temp;
				}
			}

		}
		
	}

}






int main(){
int size_arr=0;
int seq_size=0;
printf("Enter the Number of Elements to be added in the array\n");
scanf("%d",&size_arr);
printf("Enter the number of sequence you want to insert:\n");
scanf("%d",&seq_size);

int A[size_arr];
int B[size_arr];


printf("Enter the numbers in array");
for(int i=0;i<size_arr;i++){
printf("\n");
scanf("%d",&A[i]);
}

int Seq[seq_size];
printf("Arr Size:%d",size_arr);
printf("Seq Size:%d",seq_size);
printf("Enter the sequence Numbers in array:");
for(int i=0;i<seq_size;i++){

printf("Index=%d",i);
scanf("%d",&Seq[i]);
if(i==seq_size-1&&Seq[i]!=1){// Providing conditions as mentioned in the question.
i--;
printf("Invalid Input please enter the last number as 1\n");
}

}

CoolSort(A,Seq,size_arr,seq_size);
//Printing the array
for(int i=0;i<size_arr;i++){
printf("%d\t",A[i]);
}

}

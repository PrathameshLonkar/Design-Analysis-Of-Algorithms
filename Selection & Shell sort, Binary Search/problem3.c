#include<stdlib.h>
#include<stdio.h>
//Here we will use the binary search algorithm as it has a complexity of O(lgn)
int FindIndex(int A[],int strt,int arr_size){
//If we have reached the last element of the array that means that we have not found the number with same index hence we will return -1
if(arr_size-1>=strt){
	//As we have a sorted array we will find the mid to compare if the index is greated than or less than or equal to the A[mid] value
	int mid = strt+(arr_size-1-strt)/2;
	//printf("Value of Mid: %d \n",mid);
	//If we find the index which is equal to the the value in array we simply return the index value
	if(A[mid]==mid+1){
		return mid;
	}
	//If the index value is less than the value in array then we will recursively call the function on the left part of the array i.e from A[0..mid-1]
	else if(A[mid]>mid+1){
		return FindIndex(A,strt,mid-1);
	}
	//else if we have a value greater than the index value then we will recursively call the function on right part of the array
	else if(A[mid]<mid+1){
		return FindIndex(A,mid+1,arr_size-1);
	}

}

return -1;

}



int main(){
	int arr_size;
	int found=0;
	//I am taking the array size manually
	printf("Enter the number of Elements to be inserted:\n");
	
	scanf("%d",&arr_size);
	
	int A[arr_size];
	
	printf("Enter the Numbers in ascending order:\n");
	
	for(int i=0;i<arr_size;i++){
		scanf("%d",&A[i]);
		if(i!=0&&A[i]<A[i-1]){
		printf("Enter valid Input\n");
		i--;
		}
	}

	found = FindIndex(A,0,arr_size);
	//printf("Value of Found :%d\n",found);
	if(found==-1){
		printf("Not Found\n");
	}else {
	printf("Index and Array value same found at index:%d \n",found+1);
	}
}

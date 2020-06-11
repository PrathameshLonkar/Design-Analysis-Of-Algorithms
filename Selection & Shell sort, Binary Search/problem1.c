#include<stdlib.h>
#include<stdio.h>


int SelectionSort(int Arr[],int arr_size){
	int min;
	int j=0;
	int temp=0;
	for(int i=0;i<arr_size-1;i++){
		min=i;
		for(j=i+1;j<arr_size;j++){
			if(Arr[j]<Arr[min]){
			min=j;
			}
		}
		//Perform the swapping operation, the minimum value will get swaapped and the array until i will be sorted
		temp=Arr[min];
		Arr[min]=Arr[i];
		Arr[i]=temp;
	
	}

}

int ModifiedSelectionSort(int Arr[],int arr_size,int k,int Mod_Arr[]){
	int min;
	int j=0;
	int temp=0;
	for(int i=0;i<k;i++){//Once the outter loop is done then we can see that the values till i are sorted hence will will run the loop until the value k
		min=i;
		for(j=i+1;j<arr_size;j++){//Inner loop willl remain the same as normal selection sort
			if(Arr[j]<Arr[min]){
				min=j;
			}
		}
		Mod_Arr[i]=Arr[min];
		temp=Arr[min];
		Arr[min]=Arr[i];
		Arr[i]=temp;
	}

}



int main(){
	int arr_size;
	int k=0;
	int choice;
	printf("Enter the size of arr:\n");
	scanf("%d",&arr_size);
	int Arr[arr_size];
	printf("Ente the elements of arr:");
	for(int i=0;i<arr_size;i++){
		scanf("%d",&Arr[i]);
	}
	
	
	int cont=1;
	while(cont!=0){
		printf("Which of the Following you want to run (1 or 2)? \n 1.) Simple Selection sort \n 2.) Modified Selection Sort");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:
				//Normal selection sort
				SelectionSort(Arr,arr_size);
				printf("Done With Sorting, Printing the elements:");
				for(int i=0;i<arr_size;i++){
					printf("%d \t",Arr[i]);
				}
				break;
			case 2:
				//Modified selection sort
				printf("Enter the Number of sorted elements required:\n");
				scanf("%d",&k);
				//initializing the array to store k sorted element
				int Mod_Arr[k];
				ModifiedSelectionSort(Arr,arr_size,k,Mod_Arr);
				
				printf("Done With Sorting, Printing the elements:");
				for(int i=0;i<k;i++){
					printf("%d \t",Mod_Arr[i]);
				}
				break;
		}
		printf("Do you want to continue ?(0/1) \n");
		scanf("%d",&cont);
	
	}
}

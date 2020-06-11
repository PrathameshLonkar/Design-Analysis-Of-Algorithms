#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define INFINITY 99999

struct priorityQueue{
	char color;
	int key;
	
}prior;

//checking If all the nodes are covered or not
bool empty(int n,struct priorityQueue queue[n]){
	int count=0;
	for(int i=0;i<n;i++){
		if(queue[i].color=='W'){
			count++;
		}
	}
	if(count>0){
		return false;
	}else{
		return true;
	}
}

//Finding the minimum
int extractMin(int n, struct priorityQueue queue[n]){
	int min = INFINITY;
	int minimum_index; 
  
	for (int i = 0; i < n; i++){ 
		if (queue[i].color != 'B' && queue[i].key < min){
			min = queue[i].key; 
			minimum_index = i;
		}
	}
    return minimum_index;
}

int prims(int n, int weights[n][n],struct priorityQueue queue[n],int index){

	int pred[n];

	//Initializing
	for (int i=0;i<n;i++){  
		queue[i].color = 'W';
		queue[i].key = INFINITY;
      
	}
	queue[index].key=0;

	pred[index]=-1;
	while(!empty(n,queue)){
		int u= extractMin(n,queue);
		for (int i=0;i<n;i++){
			if (weights[u][i] != 0 && queue[i].color == 'W' && weights[u][i] < queue[i].key){
			queue[i].key=weights[u][i];
			pred[i]=u;
			}
      
		}
      		queue[u].color='B';
      
      
	}
	printf("priority queue:\n");
	for(int i=0;i<n;i++){
		printf("%c\t",queue[i].color);
		printf("%d\n",queue[i].key);
	}
	printf("\n");
      //printing the node and parent node and the distance between them
	printf("Destination - Source\t Distance\n"); 
    	for (int i=0; i<n;i++) {
	        int j=pred[i];
	        printf("%d\t - \t%d \t %d \n", pred[i], i, weights[i][j]);
        
        } 
}


int main(){
	int n=0,index=0;
	printf("Enter the Number of nodes in the graph \n");
	scanf("%d",&n);

	struct priorityQueue priorQ[n];
	int weights[n][n];
	printf("------------!!!! If there Is no connection between edges please enter 0 instead of a huge number !!!!----------\n");
	printf("Enter the Adjacency matrix values \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&weights[i][j]);
		}
	}
	printf("Enter the root of the graph\n");
	scanf("%d",&index);
	
	//printin the adjacency matrix
	printf("Adjacency Matrix Is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",weights[i][j]);
		}
		printf("\n");
	}

	prims(n,weights,priorQ,index);

}

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define INFINITY 99999

struct Map{
	int dijPath;

}Path;

struct Dijsktra{
	bool completed;
	int distance;
	int path;
}Dij;

//Finding minimum node in d
int findMin(int no, struct Dijsktra d[no]){
int min = INFINITY;
int minimum_index; 
  
    for (int i = 0; i < no; i++){ 
        if (d[i].completed != true && d[i].distance < min){
            min = d[i].distance; 
            minimum_index = i;
            }
  }
  	
  d[minimum_index].completed=true;
    return minimum_index;
}

//To check if the all nodes in D are covered or not
bool completed(int no,struct Dijsktra d[no]){
int count=0;
for(int i=0;i<no;i++){
	if(d[i].completed == false){
		count++;
	}
}
	if(count>0){
		return false;
	}else{
		return true;
	}
}


int Dijkstras(int no, int cost[no][no], int root){

	
	struct Map n[no];
	struct Dijsktra d[no];

	int k=0;
	n[k].dijPath = root;
	k++;
	for(int i=0;i<no;i++){
		d[i].completed = false;
	}


	d[root].completed = true;
	
	//Initializing structure
	for(int i=0;i<no;i++){
	
		if(cost[root][i]!=0 && d[i].completed !=true){
			d[i].distance = cost[root][i];
			d[i].path = root;

		}else{
			d[i].distance = INFINITY;
			d[i].path = -1;

		}

	}
	//while all the nodes in graph are not completed
	while(!completed(no,d)){
		//finding the current minimum node from D structure 
		int u = findMin(no,d);

		n[k].dijPath=u;
		k++;
		
		//printing the Distance and path after each step
		printf("Dijsktra distance and path:\n");
		for(int i=0;i<no;i++){
      			if(d[i].completed == false){
      				printf("%d \t",d[i].distance);
      				printf("%d\t -\t",i);
      				printf("%d\n",d[i].path);
      			}
      		}
		for(int i=0;i<no;i++){

			if(d[i].completed != true && cost[u][i] != 0){
				int original =d[i].distance;
				int updated = d[u].distance + cost[u][i];
				if(original<updated){

					continue;
				}else{

					d[i].distance = updated;
					d[i].path = u;

				}
			}

		}


	}
	//printing the source of each node and distance from root node
	printf("Distance\tDestination - Source\n");
      for(int i=0;i<no;i++){
      
      	printf("%d \t",d[i].distance);
      	printf("\t%d\t -\t",i);
      	printf("%d\n",d[i].path);
      
      		}
      printf("Path:\n");
      for(int i=0;i<no;i++){
      printf("%d\t",n[i].dijPath);
      }
	printf("\n");
}

int main(){

	int no=0,root;
	printf("Enter the Number of nodes in the graph \n");
	scanf("%d",&no);

	int cost[no][no];
	printf("------------!!!! If there Is no connection between edges please enter 0 instead of a huge number !!!!----------\n");
	printf("Enter the Adjacency matrix / cost values \n");
	for(int i=0;i<no;i++){
		for(int j=0;j<no;j++){
			scanf("%d",&cost[i][j]);
		}
	}

	printf("Enter the starting point of the graph or index at which we will start like 0 or 1 or 2 etc\n");
	scanf("%d",&root);
	
	//Printing the adjacency matrix
	for(int i=0;i<no;i++){
		for(int j=0;j<no;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	Dijkstras(no,cost,root);

}

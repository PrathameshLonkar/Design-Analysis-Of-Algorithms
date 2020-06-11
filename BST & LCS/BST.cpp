#include <iostream>
//#include <iomanip>

using namespace std;
#include<stdlib.h>
#include "BST.h"

int count =0;		

bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   BinNode * travers = locptr;
   bool found = false;
   while (!found && travers != NULL)
   {
      if (item < travers->data)       // descend left
        travers = travers->left;
      else if (travers->data < item)  // descend right
        travers = travers->right;
      else                           // item found
        found = true;
   }
   return found;
}

//As I am using a different structure than that provided by prof i have created a different insert function for BST
void BST::insert(const int & item)
{
   
      BinNode * New= new BinNode;
      BinNode *trav=NULL;
      BinNode *temp=NULL;
      New->data=item;
      if(myRoot==NULL)
	{
		myRoot=New;
		return;
	}
	trav=myRoot;
	
	while(trav!=NULL)
	{
		temp=trav;
		if(New->data==trav->data){
			cout<<"Invalid Entry as data already present\n";
			break;
		}
		else if(New->data>trav->data)
		{
			trav=trav->right;
		}
		else if(New->data<trav->data)
		{
			trav=trav->left;
		}
	}
	if(New->data>temp->data&&temp->right==NULL)
	{
		temp->right=New;
	}
	else if(New->data<temp->data&&temp->left==NULL)
	{
		temp->left=New;
	}
}

void BST :: pre(){
	BinNode * New =NULL;
	New=myRoot;
	cout<<"Root Element is\t"<<New->data<<"\n";
	preOrder(New);
}

//printing the nodes in preOrder
void BST:: preOrder(BinNode * temp){
if(temp==NULL){
return;
}
cout<<temp->data<<"\t";
preOrder(temp->left);
preOrder(temp->right);

}
void BST :: InO(){
	BinNode *New =NULL;
	New = myRoot;
	cout<<"Root Element is\t"<<New->data<<"\n";
	InOrder(New);
}
//printing the nodes in InOrder
void BST :: InOrder(BinNode * temp){
	if(temp==NULL){
	return;
	}
	
	InOrder(temp->left);
	cout<<temp->data<<"\t";
	InOrder(temp->right);

}

int BST :: CountNodes(){
	BinNode *New = NULL;
	New = myRoot;
	
	cnt(New);
	
	
	return count;
}
//counted the number of nodes recursively using the inorder printing method
int BST :: cnt(BinNode * temp){
	if(temp==NULL){
	return 0;
	}
	
	cnt(temp->left);
	count ++;
	cnt(temp->right);
}
//Searching for a particular node for deletion
BinNode * BST :: searchNode(BinNode * temp, int item){

while (temp != NULL)
   {
      if (item < temp->data)       // descend left
        temp = temp->left;
      else if (temp->data < item)  // descend right
        temp = temp->right;
      else if(temp->data == item)  // item found
        return temp;
      else if(temp==NULL)
        return NULL;   
   }
   


}
//Findinf the parent of a node which is to be deleted
BinNode * BST :: FindParent(BinNode * temp){
BinNode * trav = NULL;
trav = myRoot;
while (trav !=NULL)
   {
      if (trav->left == temp)       // descend left
        return trav;
      else if (trav->right == temp)  // descend right
        return trav;
      else if(temp->data<trav->data)                         // item found
        trav= trav->left;
      else if(temp->data>trav->data)
        trav=trav->right;
        else if(trav==NULL)
        return NULL;
   }
}

BinNode * BST :: searchReplacement(BinNode * temp){
while(temp->right != NULL){
		temp = temp->right;
		}
		
	return temp;
}
void BST :: NodeDelete(int item){

	BinNode * DelNode =NULL;
	BinNode * temp = NULL;
	temp= myRoot;
	DelNode =searchNode(temp,item);
	if(DelNode != NULL)
	{
		if(DelNode->left != NULL && DelNode->right != NULL)
		{
			BinNode *tempNode = searchReplacement(DelNode->left);
			DelNode->data = tempNode->data;
			if(tempNode->left != NULL || tempNode->right != NULL)
			{	
				BinNode  * ParentNode = FindParent(tempNode);
				if(ParentNode->left == tempNode)
				{
					if(tempNode->left != NULL)
					{
						ParentNode->left = tempNode->left;
						
		
					}			
					else if(tempNode->left == NULL)
					{
						ParentNode->left = tempNode->right;
						
					}
				}
				else if(ParentNode->right == tempNode)
				{
					if(tempNode->right != NULL)
					{
						ParentNode->right = tempNode->right;
						
			
					}
					else if(tempNode->right == NULL)
					{
						ParentNode->right = tempNode->left;
						
					}
				}
	
				free(tempNode);
		
			}
			else if(tempNode->left == NULL || tempNode->right == NULL)
			{
				BinNode  * Parent = FindParent(tempNode);
				if(Parent->right == tempNode)
					Parent->right = NULL;
			
				else if(Parent->left == tempNode)
					Parent->left = NULL;
				
				free(tempNode);
			}
		}
		else if(DelNode->left == NULL && DelNode->right == NULL)
		{	
			if(myRoot != DelNode)
			{
				BinNode  * Parent = FindParent(DelNode);
				if(Parent->right == DelNode)
					Parent->right = NULL;
			
				else if(Parent->left == DelNode)
					Parent->left = NULL;
				
				free(DelNode);
			}
			else if(myRoot == DelNode)
			{
				free(DelNode);
				myRoot = NULL;
				
			}
		}
		else if((DelNode->left == NULL && DelNode->right != NULL) || (DelNode->left != NULL && DelNode->right == NULL))
		{
			if(myRoot != DelNode)
			{
				BinNode  * Parent = FindParent(DelNode);
				if(Parent->left == DelNode)
				{
					if(DelNode->left != NULL)
					{
						Parent->left = DelNode->left;
						
			
					}
					else if(DelNode->left == NULL)
					{
						Parent->left = DelNode->right;
						
					}
				}
				else if(Parent->right == DelNode)
				{
					if(DelNode->right != NULL)
					{
						Parent->right = DelNode->right;
						
		
					}
					else if(DelNode->right == NULL)
					{
						Parent->right = DelNode->left;
						
					}
				}

				free(DelNode);
			}
			else if(myRoot == DelNode)
			{
				if(DelNode->left != NULL)
					myRoot = DelNode->left;
				else if((DelNode->left == NULL))
					myRoot = DelNode->right;
				free(DelNode);
				
			}
		}
	}
}

BinNode * BST :: ConvertToAvl(){
	
	BinNode * root =NULL;
	root = myRoot;
	myRoot = BalanceBST(root);
	cout<<"New Root is:\t"<<myRoot->data<<"\n";
	
}

//calculating the maximum height of each tree
int BST :: max_height(BinNode * temp){
	int height = 0;
     if (temp != NULL)
     {
        int left_tree_height = max_height(temp->left);
         int right_tree_height = max_height(temp->right);
         int max_height;
         if(left_tree_height>right_tree_height)
         {
         	max_height=left_tree_height;
         }
         else{
         	max_height=right_tree_height;
         }
         
         height = max_height + 1;
     }
     return height;
}
//Was only able to perform a right left rotation 
BinNode * BST :: BalanceBST(BinNode * temp){
	int left_tree_height = max_height(temp->left);
     	int right_tree_height = max_height(temp->right);
     	int height_difference= left_tree_height - right_tree_height;
     	cout<<"\n Height Difference is: \t"<<height_difference<<"\n";
	if (height_difference > 1)
     	{
       		
         		cout<<"\nPerforming RL rotation\n";
         		BinNode * trav;
    			BinNode *trav1;
    			BinNode *trav2;
    			trav = temp->right;
    			trav1 = temp->left;
     			trav2 = trav1->right;
     			trav->left = trav2->right;
     			trav1->right=trav2->left;
     			trav2->left=trav1;
     			trav2->right=temp;
     			temp=trav2;
     			
     			
             		
             		
             		
     	}
     
     return temp;	

}

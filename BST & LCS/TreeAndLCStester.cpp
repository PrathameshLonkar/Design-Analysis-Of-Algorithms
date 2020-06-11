/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.cpp"
//#include "BST.h"

int LongestCommonSubSeq(char X[],char Y[],int xsize,int ysize){
int table[xsize+1][ysize+1];
	for(int i=0;i<xsize+1;i++){
		for(int j=0;j<ysize+1;j++){
			if(j==0||i==0){
			
				table[i][j]=0;
			}
		}
	}

	for(int i = 1; i <= xsize; i++)
 	{
	   	for(int j = 1; j <= ysize; j++)
	   	{
	     		if(X[i-1] == Y[j-1])
	     		{
	       			table[i][j] = table[i-1][j-1] + 1;
	      
	     		}
	     		else if(X[i-1]!=Y[j-1]){
	     		
		     		if(table[i-1][j] >= table[i][j-1])
		     		{
		       			table[i][j] = table[i-1][j];
		      
		     		}
		     		else
		     		{
		       			table[i][j] = table[i][j-1];
		     
		     		}
		     		
	     		}
	     
	   	}
 	}
 	
 	 for(int i=0;i<=xsize;i++){
	for(int j=0;j<=ysize;j++){
		cout<<table[i][j]<<"\t";
	
	}
	cout<<"\n";
	}
	cout<<"The Length of the Longest Common Subsequence is :"<<table[xsize][ysize]<<"\n";
 	
}

int main()
{
int choice=0;
int choice1=0;
while(choice!=3){
cout<<"\nWhich code to run ?1.) BST 2.)LCS 3.)Exit\n";
cin>>choice;
switch(choice){

	case 1:
	{
	   int height=0;
	   int del;
	   // Testing Constructor and empty()
	   BST intBST;            // test the class constructor
	   //cout << "Constructing empty BST\n";
	   //cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

	   // Testing insert
	   cout << "\nNow insert a bunch of integers into the BST."
		   "\nTry items not in the BST and some that are in it:\n";
	   int number;
	   for (;;)
	   {
	      cout << "Item to insert (-999 to stop): ";
	      cin >> number;
	      if (number == -999) break;
	      intBST.insert(number);
	   }
	   //cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
	   while(choice1!=8){
		cout<<"Choose The following operations to perform:\n";
		cout<<"1.)Insert Node\n";
		cout<<"2.)Search Node\n";
		cout<<"3.)Print in PreOrder\n";
		cout<<"4.)Print in InOrder\n";
		cout<<"5.)Number of Nodes in Tree\n";
		cout<<"6.)Delete Node\n";
		cout<<"7.)Convert to Avl\n";
		cout<<"8.)Exit\n";
		cin>>choice1;
		switch(choice1){
		
			case 1:
			{
				 cout << "Item to insert : ";
	      			 cin >> number;
	      			 intBST.insert(number);
	      			 break;
			}
			break;
			case 2:
			{
				// Testing search()
	   			cout << "\n\nNow testing the search() operation."
		   			"\nTry both items in the BST and some not in it:\n";
	   			for (;;)
	   			{
	      				cout << "Item to find (-999 to stop): ";
	      				cin >> number;
	      				if (number == -999) break;
	      				cout << (intBST.search(number) ? "Found" : "Not found") << endl;
	   			}
			
			}
			break;
			case 3:
			{
				cout<<"Printing preorder traversal\n";
	   			intBST.pre();
				
			}
			break;
			case 4:
			{
				cout<<"\nPrinting InOrder traversal\n";
	   			intBST.InO();
			
			}
			break;
			case 5:
			{
				cout<<"\nPrinting Number of Nodes in the tree";
	   			height= intBST.CountNodes();
	   			cout<<"\t"<<height<<"\n";
	   
			
			
			}
			break;
			case 6:
			{
				for (;;)
	   			{
	      				cout << "Item to Delete (-999 to stop): ";
	      				cin >> del;
	      				if (del == -999) break;
	      				intBST.NodeDelete(del);
	      				intBST.pre();
	   			}	
			
			}
			break;
			case 7:
			{
				intBST.ConvertToAvl();
	   			intBST.pre();
	   			
			
			}
			break;
			case 8:
			{
				cout<<"GoodBy and Exiting";
				
			}
			break;
	   
	 
	   	}
	   }
	   }
	   break;
   
   case 2:
   {
   int xsize=0;
   int ysize=0;
   
   cout<<"Enter the Number of elements if X String\n";
   cin>>xsize;
   char X[xsize];
   cout<<"Enter the X string \n";
   for(int i=0;i<xsize;i++){
   cin>>X[i];
   }  
   cout<<"Enter the number of elements in Y String\n";
   cin>>ysize;
   char Y[ysize];
   int table[xsize+1][ysize+1];
   cout<<"Enter the Y string\n";
   for(int i=0;i<ysize;i++){
   cin>>Y[i];
   
   }
   int txsize=xsize+1;
   int tysize=ysize+1;
   
   LongestCommonSubSeq(X,Y,xsize,ysize);
  
   }		
   break;
   }
   }
   
}

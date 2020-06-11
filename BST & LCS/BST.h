#include <iostream>
using namespace std;  

#ifndef BST_H
#define BST_H

struct BinNode
 {
     int data;
     struct BinNode *left=NULL;
     struct BinNode *right=NULL;
 }*myRoot=NULL;
 
class BST
{
 public:
  /***** Function Members *****/
  //BST();
  //bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void pre();
  void preOrder(BinNode * );
  void InO();
  void InOrder(BinNode * );
  int CountNodes();
  int cnt(BinNode *);
  BinNode * searchReplacement(BinNode * );
  BinNode * FindParent(BinNode * );
  BinNode * searchNode(BinNode * , int item);
  void NodeDelete(int item);
  BinNode * ConvertToAvl();
  int max_height(BinNode *);
  BinNode * BalanceBST(BinNode *);
	
	
};
#endif

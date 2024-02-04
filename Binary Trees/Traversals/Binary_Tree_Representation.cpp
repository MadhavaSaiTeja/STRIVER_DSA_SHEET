#include <bits/stdc++.h>
using namespace std;

struct Node{
  public:
  // Defining value of the node.
  int data;

  // Left reference ptr to the node.
  struct Node* left;

  // Right reference ptr to the node.
  struct Node* right;

  // Method to initialize the above values.
  Node (int val)
  {
    data = val;
    left = right = NULL; 
  }
};

int main()
{
  // Creating a new node by using dynamic allocation.
  struct Node* root = new Node(1);
  root -> left = new Node(2);
  root -> right = new Node(3);
  root -> left -> right = new Node(5);

  return 0;
}
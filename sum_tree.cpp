/*
Source: GeeksforGeeks - Solution Runtime: 0.02s
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where value of every node x is equal to sum of nodes present in its left subtree and right subtree of x. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if passed tree is Sum Tree, else false

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 1000
1 <=Data of a node<= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
0

There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 3, left child of 3 is 1 and right child of 3 is 2.   Second test case represents a tree with 4 edges and 5 nodes.
*/

{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool isSumTree(struct Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isSumTree(root) << endl;
  }
  return 0;
}
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

bool isLeaf(Node *leaf){
    if(leaf->left == NULL && leaf->right == NULL){
        return true;
    }
    return false;
}

bool isTreeUtil(Node* root, int *sum){

    if(root == NULL){
        *sum = 0;
        return true;
    }

    if(isLeaf(root)){
        *sum = root->data;
        return true;
    }

    int ls = 0, rs = 0;
    bool lsr = isTreeUtil(root->left, &ls);
    bool rsr = isTreeUtil(root->right, &rs);

    *sum = ls + rs + root->data;

    return ((ls + rs == root->data)&&lsr&&rsr);
}

bool isSumTree(Node* root)
{
    if(root == NULL){
        return true;
    }
    int sum = 0;

    return isTreeUtil(root, &sum);
}

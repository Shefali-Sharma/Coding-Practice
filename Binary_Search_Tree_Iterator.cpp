/*
Source: LeetCode, Better than 94.20%
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.

Note:
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/

#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    stack<TreeNode*> myStack;
    void createStack(TreeNode *root){
        TreeNode* temp = root;
        
        while(temp!=NULL){
            myStack.push(temp);
            temp = temp->left;
        }
    }
    BSTIterator(TreeNode* root) {
        createStack(root);
        
    }
    
    /** @return the next smallest number */
    int next() {
        if(!myStack.empty()){
            TreeNode* curr = myStack.top();
            myStack.pop();
            if(curr->right != NULL){
                createStack(curr->right);
            }
            return curr->val;
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!myStack.empty());
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
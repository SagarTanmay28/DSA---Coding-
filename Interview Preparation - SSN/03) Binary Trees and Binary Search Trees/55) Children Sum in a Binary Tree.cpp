Given the root of a binary tree, determine whether the tree satisfies the Children Sum Property. In this property, 
each non-leaf node must have a value equal to the sum of its left and right children's values. 
A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.
Return true if every node in the tree satisfies this condition, otherwise return false.

  class Solution {
  public:
    int solve(Node* root){
        if(root == NULL) return 1;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int leftSum = 0;
        int rightSum = 0;
        
        if(root->left) leftSum = root->left->data;
        if(root->right) rightSum = root->right->data;
        
        return (root->data == leftSum + rightSum) && (solve(root->left) && solve(root->right));
    }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
    }
};


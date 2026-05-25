

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.


class Solution {
public:
    int checkMax(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        // We are doing post order here 

        int leftMaxSum = max(0,checkMax(root->left,maxi));
        int rightMaxSum = max(0,checkMax(root->right,maxi));

        int pathSum = root->val + leftMaxSum + rightMaxSum;
        maxi = max(maxi,pathSum);

        return root->val + max(leftMaxSum,rightMaxSum);
    }
    
    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        checkMax(root,maxi);

        return maxi;
        
    }
};


      10
     /  \
    2    10
        /  \
       20   1
leftMaxSum = 20
rightMaxSum = 1

pathSum = 10 + 20 + 1 = 31
  
Parent cannot take both 20 and 1.

So return:

10 + max(20,1) = 30
  

    
  

    



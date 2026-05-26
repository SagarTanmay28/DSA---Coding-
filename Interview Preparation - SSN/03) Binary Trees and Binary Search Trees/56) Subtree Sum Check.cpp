what the code if question is not just the sum of left and right node
but node value should be equal to the entire sum of leftsubtree + rightsubtree


Efficient Idea

Use postorder traversal:

First calculate left subtree sum
Then right subtree sum
Check if current node satisfies condition
Return total subtree sum upward

class Solution {
public:

    bool valid = true;

    int solve(Node* root) {

        if(root == NULL)
            return 0;

        // Leaf node
        if(root->left == NULL && root->right == NULL)
            return root->data;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Check condition
        if(root->data != leftSum + rightSum)
            valid = false;

        // Return total subtree sum including current node
        return root->data + leftSum + rightSum;
    }

    bool isSumTree(Node* root) {

        valid = true;
        solve(root);

        return valid;
    }
};

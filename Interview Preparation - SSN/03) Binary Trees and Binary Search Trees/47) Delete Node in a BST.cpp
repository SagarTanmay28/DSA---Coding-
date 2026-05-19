class Solution {
public:
    TreeNode* iop(TreeNode* root, int key){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            // Case 1 : Leaf Node
            if(root->left == NULL && root->right == NULL) return NULL;
            
            // Case 2 : 1 Node
            else if(root->left == NULL || root->right == NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }

            // Case 3 : 2 Nodes
            else{
                TreeNode* pred = iop(root,key);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        }

        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }

        else{
            root->right = deleteNode(root->right,key);
        }

        return root;
    }
};

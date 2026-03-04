//******************************************************************Approach-1****************************************************************************************
class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& ans){
        if(root == NULL) return;
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root,ans);

        int n = ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
        return;
    }
};
//******************************************************************Recursion*****************************************************************************************
// Method 2 :: Recursion 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        root->right = NULL;
        
        flatten(l);
        flatten(r);

        root->right = l;
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;
        temp->right = r;
        
    }
};
//******************************************************************Morris Traversal********************************************************************************
// Morris Traversal O(1) Space 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                // save the right
                TreeNode* r = curr->right;
                curr->right = curr->left;
                // finding pred
                TreeNode* pred = curr->left;
                while(pred->right) pred = pred->right;
                // link
                pred->right = r;
                curr = curr->left;
            }
            else curr = curr->right;
        }

        TreeNode* temp = root;
        while(temp->right){
            temp->left = NULL;
            temp = temp->right;
        }
        return;
        
    }
};

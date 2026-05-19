class Solution {
  public:
  
    bool isLeaf(Node* root){
        return root->left == NULL && root->right == NULL;
    }
  
    void left_boundry(Node* root, vector<int>& ans){
        
        // exclude NULL and leaf
        if(root == NULL || isLeaf(root)) return;
        
        ans.push_back(root->data);
        
        if(root->left != NULL)
            left_boundry(root->left, ans);
        else if(root->right != NULL)
            left_boundry(root->right, ans);
    }
    
    void right_boundry(Node* root, vector<int>& ans){
        
        // exclude NULL and leaf
        if(root == NULL || isLeaf(root)) return;
        
        if(root->right != NULL)
            right_boundry(root->right, ans);
        else if(root->left != NULL)
            right_boundry(root->left, ans);
        
        ans.push_back(root->data); // bottom-up
    }
    
    void bottom_boundry(Node* root, vector<int>& ans){
        
        if(root == NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        bottom_boundry(root->left, ans);
        bottom_boundry(root->right, ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        // add root only if not leaf
        if(!isLeaf(root))
            ans.push_back(root->data);
        
        // left boundary
        left_boundry(root->left, ans);
        
        // leaves
        bottom_boundry(root, ans);
        
        // right boundary
        right_boundry(root->right, ans);
        
        return ans;
    }
};

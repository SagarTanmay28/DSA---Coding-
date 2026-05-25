// DFS 
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    
    void nthLevel(TreeNode* root, int curr, int level, vector<int> &ans){
        if(root == NULL) return;
        if(curr == level){
            ans[curr] = root->val;
            return;
        }
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    void levelOrder(TreeNode* root, vector<int> &ans){
        int n = ans.size();
        for(int i=0;i<n;i++){
            nthLevel(root,0,i,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        levelOrder(root,ans);
        return ans;
        
    }
};


// Preorder 
class Solution { // Preorder
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    
    void preorder(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL) return;
        ans[level] = root->val;
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
        
    }
};

// More Clean 
class Solution {
public:

    void dfs(TreeNode* root, vector<int>& ans, int level){

        if(root == NULL) return;

        // first node visited at this level
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        // go right first
        dfs(root->right, ans, level + 1);

        // then left
        dfs(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        dfs(root, ans, 0);

        return ans;
    }
};

// BFS 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size()>0){
            int levelSize = q.size();
            int rightmost = 0;
            for(int i=0;i<levelSize;i++){
                TreeNode* node = q.front();
                q.pop();
                rightmost = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(rightmost);
        }
        return result;
        
    }
};

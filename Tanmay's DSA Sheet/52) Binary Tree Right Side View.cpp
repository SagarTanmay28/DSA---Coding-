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

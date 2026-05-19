class Solution {
public:
    void fill_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        fill_parent(root->left,parent);
        fill_parent(root->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        // child -> parent
        unordered_map<TreeNode*,TreeNode*> parent;
        fill_parent(root,parent);
        
        // visited
        unordered_set<TreeNode*> st;
        st.insert(target);
        // queue
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});

        while(q.size() > 0){
            pair<TreeNode*,int> p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int val = p.second;
            if(val == k) ans.push_back(temp->val);
            if(val > k) return ans;

            if(temp->left != NULL){
                if(st.find(temp->left) == st.end()){
                    q.push({temp->left,val+1});
                    st.insert(temp->left);
                }
            }

            if(temp->right != NULL){
                if(st.find(temp->right) == st.end()){
                    q.push({temp->right,val+1});
                    st.insert(temp->right);
                }
            }

            if(parent.find(temp) != parent.end()){
                 if(st.find(parent[temp]) == st.end()){
                    q.push({parent[temp],val+1});
                    st.insert(parent[temp]);
                }
            }
        }

        return ans;
    }
};

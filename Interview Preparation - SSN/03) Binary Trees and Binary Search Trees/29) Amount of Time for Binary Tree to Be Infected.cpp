You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

class Solution {
public:
    TreeNode* first = NULL;
    // Find Start root
    void find_start(TreeNode* root, int start){
        if(root == NULL) return;
        if(root->val == start){
            first = root;
            return;
        }
        find_start(root->left,start);
        find_start(root->right,start);
    }
    // fill <child,parent>
    void fill_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        fill_parent(root->left,parent);
        fill_parent(root->right,parent);
    }

    int amountOfTime(TreeNode* root, int start) {
        find_start(root,start);
        unordered_map<TreeNode*,TreeNode*> parent;
        fill_parent(root,parent);

        unordered_set<TreeNode*> st;
        queue<pair<TreeNode*,int>> q;
        st.insert(first);
        q.push({first,0});

        int max_len = 0;

        while(q.size() > 0){
            pair<TreeNode*,int> p = q.front();
            q.pop();

            int val = p.second;      
            TreeNode* temp = p.first;
            max_len = max(max_len,val);
            
            // left
            if(temp->left != NULL){
                if(st.find(temp->left) == st.end()){
                    q.push({temp->left,val+1});
                    st.insert(temp->left);
                }
            }
            // right 
            if(temp->right != NULL){
                if(st.find(temp->right) == st.end()){
                    q.push({temp->right,val+1});
                    st.insert(temp->right);
                }
            }
            // parent
            if(parent.find(temp) != parent.end()){
                if(st.find(parent[temp]) == st.end()){
                    q.push({parent[temp],val+1});
                    st.insert(parent[temp]);
                }
            }

        }

        return max_len;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 1. map sorts columns
        // 2. inner map sorts rows
        // 3. multiset sorts values at same position

        //column -> row -> sorted values
        map<int, map<int, multiset<int>>> mp;

        // queue 
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(q.size() > 0){

            auto front = q.front();
            q.pop();

            TreeNode* temp = front.first;
            int row = front.second.first;
            int col = front.second.second;

            mp[col][row].insert(temp->val);

            if(temp->left != NULL){
                q.push({temp->left,{row + 1,col - 1}});
            }

            if(temp->right != NULL){
                q.push({temp->right,{row + 1,col + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto &x : mp){

            vector<int> nums;

            for(auto &y : x.second){
                nums.insert(nums.end(),
                            y.second.begin(),
                            y.second.end());
            }

            ans.push_back(nums);
        }
        
        return ans;
    }
};
};

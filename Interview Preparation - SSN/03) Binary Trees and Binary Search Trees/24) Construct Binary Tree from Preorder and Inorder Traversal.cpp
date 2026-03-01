

class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi){
        if(prelo > prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;
        int i = inlo;
        while(i <= pre.size()){
            if(in[i] == pre[prelo]) break;
            i++;
        }

        int leftCount = i - inlo;
        int rightCount = inhi - i;

        root->left = build(pre, prelo + 1, prelo + leftCount, in, inlo, i - 1);
        root->right = build(pre, prelo + leftCount + 1, prehi, in, i + 1, inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre, 0, n-1, in, 0, n-1);
        
    }
};




class Solution { // Using Map to lookups become O(1)
public:

    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi){
        if(prelo > prehi) return NULL;

        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;

        int inRootIndex = inorderIndex[pre[prelo]]; // O(1) lookup
        int leftCount = inRootIndex - inlo;

        root->left = build(pre, prelo + 1, prelo + leftCount, in, inlo, inRootIndex - 1);
        root->right = build(pre, prelo + leftCount + 1, prehi, in, inRootIndex + 1, inhi);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        for(int i = 0; i < n; i++) {
            inorderIndex[in[i]] = i;
        }
        return build(pre, 0, n - 1, in, 0, n - 1);
    }
};

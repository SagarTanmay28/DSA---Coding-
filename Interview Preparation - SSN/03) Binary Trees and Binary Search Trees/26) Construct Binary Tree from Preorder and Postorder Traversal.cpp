class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& post, int polo, int pohi){
        
        if(prelo > prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;

        int leftRoot = pre[prelo + 1];
        int i = polo;
        while(i <= pohi){
            if(post[i] == leftRoot) break;
            i++;
        }

        int leftCount = i + 1 - polo;
        int rightCount = pohi - i - 1;

        root->left = build(pre, prelo + 1, prelo + leftCount, post, polo, i);
        root->right = build(pre, prelo + leftCount + 1, prehi, post, i + 1, pohi - 1);

        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(pre.size() == 1) return new TreeNode(pre[0]);
        return build(pre,0,n-1,post,0,n-1);
        
    }
};

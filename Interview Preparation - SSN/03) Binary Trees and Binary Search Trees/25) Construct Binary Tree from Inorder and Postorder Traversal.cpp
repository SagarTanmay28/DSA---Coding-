class Solution { // Try HashTable Solution to Optimise TC 
public:
    TreeNode* build(vector<int>& in, int inlo, int inhi, vector<int>& post, int polo, int pohi){
        if(inlo > inhi) return NULL;
        TreeNode* root = new TreeNode(post[pohi]);
        if(inlo == inhi) return root;

        int i = inlo;
        while(i <= in.size()){
            if(in[i] == post[pohi]) break;
            i++;
        }

        int leftCount = i - inlo;
        int rightCount = inhi - i;

        root->left = build(in, inlo, i - 1, post, polo, polo + leftCount - 1);
        root->right = build(in, i + 1, inhi, post, polo + leftCount, polo + leftCount + rightCount - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in, 0, n-1, post, 0, n-1);
        
    }
};

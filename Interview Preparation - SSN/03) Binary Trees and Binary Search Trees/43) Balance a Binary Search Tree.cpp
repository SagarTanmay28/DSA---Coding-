class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;

        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }

    TreeNode* construct(int l, int r, vector<int>& vec){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(vec[mid]);
        root->left = construct(l,mid-1,vec);
        root->right = construct(mid+1,r,vec);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);

        int l = 0;
        int r = vec.size() - 1;

        return construct(l,r,vec);
    }
};

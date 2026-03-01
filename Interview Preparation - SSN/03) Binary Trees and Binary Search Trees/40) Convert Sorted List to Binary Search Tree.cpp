class Solution {
public:
    TreeNode* convert(vector<TreeNode*>& ans,int lo, int hi){
        if(lo > hi) return NULL;

        int mid = lo + (hi - lo)/2;

        TreeNode* root = ans[mid];

        root->left = convert(ans,lo,mid-1);
        root->right = convert(ans,mid+1,hi);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<TreeNode*> ans;

        ListNode* temp = head;
        while(temp){
            TreeNode* temp_root = new TreeNode(temp->val);
            ans.push_back(temp_root);
            temp = temp->next;
        }
        
        int n = ans.size();
        return convert(ans,0,n-1);
        
    }
};

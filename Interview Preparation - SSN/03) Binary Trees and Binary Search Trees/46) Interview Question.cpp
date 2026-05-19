pair<TreeNode*, TreeNode*> findPredSuc(TreeNode* root, int key) {

    TreeNode* pred = NULL;
    TreeNode* suc = NULL;

    TreeNode* curr = root;

    while (curr) {

        if (curr->val == key) {

            // predecessor = max in left subtree
            if (curr->left) {
                TreeNode* t = curr->left;
                while (t->right) t = t->right;
                pred = t;
            }

            // successor = min in right subtree
            if (curr->right) {
                TreeNode* t = curr->right;
                while (t->left) t = t->left;
                suc = t;
            }

            break;
        }

        else if (key < curr->val) {
            suc = curr;          // potential successor
            curr = curr->left;
        }

        else {
            pred = curr;         // potential predecessor
            curr = curr->right;
        }
    }

    return {pred, suc};
}

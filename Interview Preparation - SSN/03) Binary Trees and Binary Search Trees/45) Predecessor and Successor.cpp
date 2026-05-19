// Predecessor  
TreeNode* inorderPredecessor(TreeNode* root) {
    if (root == NULL || root->left == NULL)
        return NULL;

    TreeNode* pred = root->left;

    while (pred->right != NULL) {
        pred = pred->right;
    }

    return pred;
}

// Successor
TreeNode* inorderSuccessor(TreeNode* root) {
    if (root == NULL || root->right == NULL)
        return NULL;

    TreeNode* suc = root->right;

    while (suc->left != NULL) {
        suc = suc->left;
    }

    return suc;
}

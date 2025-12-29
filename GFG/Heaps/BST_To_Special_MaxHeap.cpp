// TC: O(n)
// SC: O(n)

int idx;

// O(n)
void inorder(Node* root, vector<int>& in) {
    if (!root) return;
    inorder(root->left, in);      // O(n)
    in.push_back(root->data);     // O(1)
    inorder(root->right, in);     // O(n)
}

// O(n)
void postorder(Node* root, const vector<int>& in) {
    if (!root) return;
    postorder(root->left, in);    // O(n)
    postorder(root->right, in);   // O(n)
    root->data = in[idx++];       // O(1)
}

// O(n)
void convertToMaxHeapUtil(Node* root) {
    idx = 0;
    vector<int> in;

    inorder(root, in);            // O(n)
    postorder(root, in);          // O(n)
}

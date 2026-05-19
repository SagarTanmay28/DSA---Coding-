// TC: O(n)
// SC: O(h)   (recursion stack)

int s;

// O(n)
int size(Node* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

// O(n)
bool isCBT(Node* root, int idx) {
    if (!root) return true;
    if (idx > s) return false;
    return isCBT(root->left, 2 * idx) && isCBT(root->right, 2 * idx + 1);
}

// O(n)
bool isMaxHeap(Node* root) {
    if (!root) return true;

    int leftVal = (root->left) ? root->left->data : INT_MIN;
    int rightVal = (root->right) ? root->right->data : INT_MIN;

    if (root->data <= leftVal || root->data <= rightVal)
        return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

// O(n)
bool isHeap(Node* root) {
    s = size(root);          // O(n)
    return isMaxHeap(root)   // O(n)
        && isCBT(root, 1);   // O(n)
}

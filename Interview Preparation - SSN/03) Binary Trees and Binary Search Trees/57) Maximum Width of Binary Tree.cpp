Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.


class Solution {
public: 
    
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        int maxWidth = 1;

        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            maxWidth = max(maxWidth, (int)(right - left + 1));

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front().first;
                unsigned long long x = q.front().second;
                q.pop();

                // normalize index at this level
                x -= left;

                if (temp->left) {
                    q.push({temp->left, 2 * x + 1});
                }
                if (temp->right) {
                    q.push({temp->right, 2 * x + 2});
                }
            }
        }

        return maxWidth;
    }
};

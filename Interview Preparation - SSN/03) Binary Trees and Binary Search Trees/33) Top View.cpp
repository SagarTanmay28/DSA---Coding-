#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Pair {
    Node* node;
    int dist;
    Pair(Node* n, int d) {
        node = n;
        dist = d;
    }
};

vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    map<int, int> mp;
    queue<Pair> q;
    q.push(Pair(root, 0));

    int minDist = INT_MAX, maxDist = INT_MIN;

    while (!q.empty()) {
        Pair front = q.front();
        q.pop();

        Node* node = front.node;
        int dist = front.dist;

        minDist = min(minDist, dist);
        maxDist = max(maxDist, dist);

        if (mp.find(dist) == mp.end())
            mp[dist] = node->data;

        if (node->left)
            q.push(Pair(node->left, dist - 1));

        if (node->right)
            q.push(Pair(node->right, dist + 1));
    }

    for (int i = minDist; i <= maxDist; i++)
        ans.push_back(mp[i]);

    return ans;
}

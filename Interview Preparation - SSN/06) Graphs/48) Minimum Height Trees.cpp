A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]


// Brute Force 

class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int height = 0;

        for (int nei : adj[node]) {
            if (nei != parent) {
                height = max(height, 1 + dfs(nei, node, adj));
            }
        }

        return height;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int minHeight = INT_MAX;
        vector<int> ans;

        for (int root = 0; root < n; root++) {
            int height = dfs(root, -1, adj);

            if (height < minHeight) {
                minHeight = height;
                ans.clear();
                ans.push_back(root);
            }
            else if (height == minHeight) {
                ans.push_back(root);
            }
        }

        return ans;
    }
};



//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(n);
        map<int, vector<int>> adj;
        
        for(vector<int> vec:edges) {
            int u = vec[0];
            int v = vec[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) //adding all leafs node so that we can remove them later
                que.push(i);
        }
        
        while(n > 2) {
            int size = que.size();
            n -= size; //removing nodes with indegreee 1
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};

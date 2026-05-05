// BFS 

class Solution {
public:
    bool isCycle(int n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(bfs(i, n, adj, vis)) return true;
            }
        }
        return false;
    }

    bool bfs(int start, int n, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<pair<int,int>> q;
        q.push({start, -1});
        vis[start] = true;

        while(q.size() > 0) {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for(int ele : adj[node]) {
                if(!vis[ele]) {
                    vis[ele] = true;
                    q.push({ele, node});
                }
                else if(ele != parent) {
                    return true;
                }
            }
        }
        return false;
    }
};

// DFS 

class Solution {
public:
    bool isCycle(int n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, n, adj, vis)) return true;
            }
        }
        return false;
    }

    bool dfs(int node, int parent, int n, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for(int ele : adj[node]) {
            if(!vis[ele]) {
                if(dfs(ele, node, n, adj, vis)) return true;
            }
            else if(ele != parent) {
                return true;
            }
        }
        return false;
    }
};

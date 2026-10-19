DFS -> 

class Solution {
public:
    typedef pair<int,int> P;
     
    void dfs(int u, vector<vector<P>> &adj, vector<bool>& vis, int &mini){

        vis[u] = true;

        for(auto P : adj[u]){

            int v = P.first;
            int dist = P.second;

            mini = min(mini,dist);

            if(!vis[v]) dfs(v,adj,vis,mini);
        }

    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<P>> adj(n);

        for(int i=0;i<(int)roads.size();i++){

            int u = roads[i][0] - 1;
            int v = roads[i][1] - 1;
            int d = roads[i][2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        int mini = INT_MAX;

        vector<bool> vis(n,false);

        dfs(0,adj,vis,mini);

        return mini;
    }
};

BFS -> 


class Solution {
public:
    typedef pair<int, int> p;

    void bfs(int u, vector<bool>& vis,
             vector<vector<p>>& adj, int& ans) {

        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nextNode : adj[node]) {
                int nxtNode = nextNode.first;
                int wt = nextNode.second;

                // Consider EVERY road, even if the city is visited
                ans = min(ans, wt);

                if (!vis[nxtNode]) {
                    vis[nxtNode] = true;
                    q.push(nxtNode);
                }
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<p>> adj(n + 1);

        for (auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1, false);
        int ans = INT_MAX;

        bfs(1, vis, adj, ans);

        return ans;
    }
};






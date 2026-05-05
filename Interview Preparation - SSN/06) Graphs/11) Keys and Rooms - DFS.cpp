class Solution {
public:
   bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        dfs(0, adj, visited);

        for(bool ele : visited) {
            if(ele == false) return false;
        }
        return true;
    }

    void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[start] = true;

        for(int ele : adj[start]) {
            if(!visited[ele]) {
                dfs(ele, adj, visited);
            }
        }
    }

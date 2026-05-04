Total TC = O(V + E)
Total SC = O(V)


class Solution {
public:
   bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        bfs(0, adj, visited);

        for(bool ele : visited) {
            if(ele == false) return false;
        }
        return true;
    }

    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);

        while(q.size() > 0) {
            int front = q.front();
            q.pop();

            for(int ele : adj[front]) {
                if(!visited[ele]) {
                    visited[ele] = true;
                    q.push(ele);
                }
            }
        }
    }
};

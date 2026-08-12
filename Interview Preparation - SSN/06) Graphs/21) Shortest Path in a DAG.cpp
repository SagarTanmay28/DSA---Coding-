Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.

Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

Examples :

Input: V = 4, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Constraint:
1 ≤ V ≤ 100
1 ≤ E ≤ min((V*(V-1))/2,4000)
0 ≤ edges[i][0], edges[i][1] < V
0 ≤  edges[i][2] ≤105

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
        }
        
        // Topological sort
        vector<int> indegree(V, 0);
        
        for(int u = 0; u < V; u++) {
            for(auto &[v, wt] : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto &[v, wt] : adj[node]) {
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Shortest distance
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        for(int node : topo) {
            
            if(dist[node] == INT_MAX)
                continue;
            
            for(auto &[v, wt] : adj[node]) {
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // Unreachable vertices
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

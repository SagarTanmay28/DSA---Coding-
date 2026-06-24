There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        // Reverse Graph 

        for(int i=0;i<n;i++){
            int u = i;

            indegree[i] += graph[i].size();

            for(int v : graph[i]){
                adj[v].push_back(u);
            }
        }

        // Kahn's Algorithm 
        
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(q.size()){

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh : adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

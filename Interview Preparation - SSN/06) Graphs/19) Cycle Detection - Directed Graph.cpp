class Solution {
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        int count = 0;
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(q.size()){
            
            int front = q.front();
            q.pop();
            
            count++;
            
            for(auto neigh : adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        
        return count < n;
    }
};

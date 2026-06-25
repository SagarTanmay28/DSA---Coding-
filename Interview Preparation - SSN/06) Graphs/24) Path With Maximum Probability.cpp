You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.



class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& probability,
                          int start_node, int end_node) {

        priority_queue<pair<double,int>> pq;

        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = probability[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> ans(n,0.0);

        ans[start_node] = 1.0;
        pq.push({1.0,start_node});

        while(!pq.empty()) {

            auto [prob,node] = pq.top();
            pq.pop();

            if(prob < ans[node]) continue;

            for(auto &[next,edgeProb] : adj[node]) {

                double newProb = prob * edgeProb;

                if(newProb > ans[next]) {
                    ans[next] = newProb;
                    pq.push({newProb,next});
                }
            }
        }

        return ans[end_node];
    }
};

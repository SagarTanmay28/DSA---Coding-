You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



class Solution {
public:
    typedef pair<int,int> pi;
    
    struct cmp {
        bool operator()(const pi &a, const pi &b) const {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();

        vector<int> ans(n+1,INT_MAX);
        ans[0] = 0;

        priority_queue< pi,vector<pi>,cmp > pq;

        vector<vector< pair<int,int> >> adj(n+1);
        // adjacency list made 
        for(int i=0;i<m;i++){
            int start = times[i][0];
            int end = times[i][1];
            int time = times[i][2];

            adj[start].push_back({end,time});
        }

        // Dijkshtras Algorithm 

        pq.push({k,0});
        ans[k] = 0;

        while(pq.size()){

            auto p = pq.top();
            pq.pop();

            int node = p.first;
            int time = p.second;

            if(time > ans[node]) continue;

            for(auto &x : adj[node]){
                int total_time = time + x.second;
                if(ans[x.first] > total_time){
                    ans[x.first] = total_time;
                    pq.push({x.first,total_time});
                }
            }
        }

        int maxi = INT_MIN;

        for(int i=1;i<=n;i++){
            if(ans[i] == INT_MAX) return -1;
            maxi = max(maxi,ans[i]);
        }

        return maxi;

    }
};

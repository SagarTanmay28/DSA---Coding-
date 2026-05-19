class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start == end) return true;

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        unordered_set<int> st;
        queue<int> q;
        q.push(start);
        st.insert(start);

        while(q.size() > 0) {
            int top = q.front();
            q.pop();

            for(int ele : adj[top]) {
                if(ele == end) return true;
                if(st.find(ele) == st.end()) {
                    q.push(ele);
                    st.insert(ele);
                }
            }
        }

        return false;
    }
};

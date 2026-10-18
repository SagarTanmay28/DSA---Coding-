You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

Initially, all stations are online (operational).

You are also given a 2D array queries, where each query is one of the following two types:

[1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

[2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the order they appear.

Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

 

Example 1:

Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

Output: [3,2,3]

Explanation:



Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
Example 2:

Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

Output: [1,-1]

Explanation:

There are no connections, so each station is its own isolated grid.
Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
Query [2,1]: Station 1 goes offline.
Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.
 

Constraints:

1 <= c <= 105
0 <= n == connections.length <= min(105, c * (c - 1) / 2)
connections[i].length == 2
1 <= ui, vi <= c
ui != vi
1 <= queries.length <= 2 * 105
queries[i].length == 2
queries[i][0] is either 1 or 2.
1 <= queries[i][1] <= c


Approach - 1 :: 

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if (par_x == par_y) return;

        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        }
        else if (rank[par_y] > rank[par_x]) {
            parent[par_x] = par_y;
        }
        else {
            parent[par_y] = par_x;
            rank[par_x]++;
        }
    }

    int getMe(int u, unordered_set<int>& st,
              vector<set<int>>& components) {
        int root = find(u);

        if (components[root].empty()) return -1;

        return *components[root].begin();
    }

    vector<int> processQueries(int c, vector<vector<int>>& edges,
                               vector<vector<int>>& queries) {

        parent.resize(c + 1);
        rank.assign(c + 1, 1);

        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }

        vector<vector<int>> adj(c + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            Union(u, v);
        }

        unordered_set<int> st;

        vector<set<int>> components(c + 1);

        for (int i = 1; i <= c; i++) {
            st.insert(i);
            components[find(i)].insert(i);
        }

        vector<int> ans;

        for (auto q : queries) {
            int isOne = q[0];
            int node = q[1];

            if (isOne == 1 && st.find(node) != st.end()) {
                ans.push_back(node);
            }
            else if (isOne != 1) {
                if (st.erase(node)) {
                    components[find(node)].erase(node);
                }
            }
            else {
                int req_node = getMe(node, st, components);
                ans.push_back(req_node);
            }
        }

        return ans;
    }
};
Approach - 2 :: 

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if (par_x == par_y) return;

        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        }
        else if (rank[par_y] > rank[par_x]) {
            parent[par_x] = par_y;
        }
        else {
            parent[par_y] = par_x;
            rank[par_x]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& edges,
                               vector<vector<int>>& queries) {

        parent.resize(c + 1);
        rank.assign(c + 1, 1);

        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }

        // Build connected components
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Store active nodes in each component
        vector<set<int>> st(c + 1);

        for (int i = 1; i <= c; i++) {
            st[find(i)].insert(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> ans;

        for (auto& q : queries) {
            int isOne = q[0];
            int node = q[1];

            int root = find(node);

            if (isOne == 1) {
                if (online[node]) {
                    ans.push_back(node);
                }
                else if (st[root].empty()) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(*st[root].begin());
                }
            }
            else {
                if (online[node]) {
                    online[node] = false;
                    st[root].erase(node);
                }
            }
        }

        return ans;
    }
};

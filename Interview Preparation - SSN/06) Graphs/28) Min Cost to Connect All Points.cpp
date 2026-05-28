You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



// Triplet Custom Sort Method 

class Solution {
public:

    class Triplet {
    public:
        int node;
        int parent;
        int dist;

        Triplet(int node, int parent, int dist) {
            this->node = node;
            this->parent = parent;
            this->dist = dist;
        }
    };

    struct cmp {
        bool operator()(Triplet &a, Triplet &b) {
            return a.dist > b.dist;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // min-heap => {dist, node, parent}
        priority_queue<Triplet, vector<Triplet>, cmp> pq;

        pq.push(Triplet(0, -1, 0));

        int sum = 0;

        vector<bool> vis(n, false);

        while (!pq.empty()) {

            Triplet top = pq.top();
            pq.pop();

            int node = top.node;
            int parent = top.parent;
            int dist = top.dist;

            if (vis[node] == true)
                continue;

            sum += dist;

            vis[node] = true;

            for (int i = 0; i < n; i++) {

                if (i == node || i == parent)
                    continue;

                if (vis[i] == true)
                    continue;

                int x1 = points[node][0];
                int y1 = points[node][1];

                int x2 = points[i][0];
                int y2 = points[i][1];

                int mDis = abs(x2 - x1) + abs(y2 - y1);

                pq.push(Triplet(i, node, mDis));
            }
        }

        return sum;
    }
};


// Optimal Solution 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {cost, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<bool> vis(n, false);

        pq.push({0, 0});

        int ans = 0;

        while (!pq.empty()) {

            auto [cost, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;

            ans += cost;

            for (int i = 0; i < n; i++) {

                if (vis[i]) continue;

                int x1 = points[node][0];
                int y1 = points[node][1];

                int x2 = points[i][0];
                int y2 = points[i][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                pq.push({dist, i});
            }
        }

        return ans;
    }
};

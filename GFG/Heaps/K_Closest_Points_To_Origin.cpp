// TC: O(n log k)
// SC: O(k)

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    // max-heap based on distance → O(1)
    priority_queue<pair<int, pair<int,int>>> pq;

    // O(n)
    for (auto &p : points) {
        int x = p[0], y = p[1];
        int dist = x * x + y * y;

        pq.push({dist, {x, y}});     // O(log k)

        if (pq.size() > k)
            pq.pop();                // O(log k)
    }

    vector<vector<int>> ans(k, vector<int>(2));

    // O(k)
    for (int i = 0; i < k; i++) {
        ans[i][0] = pq.top().second.first;
        ans[i][1] = pq.top().second.second;
        pq.pop();                    // O(log k)
    }

    return ans;
}

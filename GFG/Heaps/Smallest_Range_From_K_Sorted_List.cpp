// TC: O(n × k log k)
// SC: O(k)

vector<int> findSmallestRange(vector<vector<int>>& arr) {

    int k = arr.size();
    int n = arr[0].size();

    // min-heap element
    struct Triplet {
        int ele, row, col;
    };

    // O(1)
    auto cmp = [](const Triplet& a, const Triplet& b) {
        return a.ele > b.ele;   // min-heap
    };

    priority_queue<Triplet, vector<Triplet>, decltype(cmp)> pq(cmp);

    int mx = INT_MIN, mn = INT_MAX;

    // O(k)
    for (int i = 0; i < k; i++) {
        mx = max(mx, arr[i][0]);   // O(1)
        mn = min(mn, arr[i][0]);   // O(1)
        pq.push({arr[i][0], i, 0}); // O(log k)
    }

    int a = mn, b = mx;

    // O(n × k log k)
    while (true) {

        Triplet top = pq.top(); 
        pq.pop();                 // O(log k)

        int ele = top.ele;
        int row = top.row;
        int col = top.col;

        // O(1)
        if (mx - ele < b - a) {
            a = ele;
            b = mx;
        }

        if (col == n - 1)
            break;

        int next = arr[row][col + 1];
        mx = max(mx, next);       // O(1)
        pq.push({next, row, col + 1}); // O(log k)
    }

    return {a, b};
}

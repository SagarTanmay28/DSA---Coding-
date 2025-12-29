// TC: O(n log k)
// SC: O(k)

void nearlySorted(vector<int>& arr, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;
    int idx = 0;

    // O(n)
    for (int ele : arr) {
        pq.push(ele);              // O(log k)

        if (pq.size() > k) {
            arr[idx++] = pq.top(); // O(1)
            pq.pop();              // O(log k)
        }
    }

    // O(k)
    while (!pq.empty()) {
        arr[idx++] = pq.top();     // O(1)
        pq.pop();                  // O(log k)
    }
}

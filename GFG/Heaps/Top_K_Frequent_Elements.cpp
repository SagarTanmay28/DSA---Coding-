// TC: O(n log k)
// SC: O(n)

vector<int> topKFrequent(vector<int>& arr, int k) {

    unordered_map<int,int> freq;

    // O(n)
    for (int ele : arr) {
        freq[ele]++;                 // O(1)
    }

    // min-heap: (frequency, element)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // O(n)
    for (auto &it : freq) {
        pq.push({it.second, it.first});   // O(log k)

        if (pq.size() > k)
            pq.pop();                     // O(log k)
    }

    vector<int> ans;

    // O(k)
    while (!pq.empty()) {
        ans.push_back(pq.top().second);   // O(1)
        pq.pop();                         // O(log k)
    }

    reverse(ans.begin(), ans.end());      // O(k)
    return ans;
}

// TC: O(n²)
// SC: O(1)

void transpose(int n, vector<vector<int>>& arr) {

    // O(n)
    for (int i = 0; i < n; i++) {

        // O(n)
        for (int j = 0; j < i; j++) {
            swap(arr[i][j], arr[j][i]);   // O(1)
        }
    }
}

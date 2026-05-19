// TC: O(n²)
// SC: O(1)

void rotateby90(vector<vector<int>>& arr) {
    int n = arr.size();

    // transpose → O(n²)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(arr[i][j], arr[j][i]);   // O(1)
        }
    }

    // reverse each column → O(n²)
    for (int col = 0; col < n; col++) {
        int i = 0, j = n - 1;

        // O(n)
        while (i < j) {
            swap(arr[i][col], arr[j][col]);   // O(1)
            i++;
            j--;
        }
    }
}

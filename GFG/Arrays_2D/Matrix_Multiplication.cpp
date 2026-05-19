// TC: O(n³)
// SC: O(1)

void multiply(const vector<vector<int>>& a,
              const vector<vector<int>>& b,
              vector<vector<int>>& c,
              int n) {

    // O(n)
    for (int i = 0; i < n; i++) {

        // O(n)
        for (int j = 0; j < n; j++) {

            // O(n)
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j]; // O(1)
            }
        }
    }
}

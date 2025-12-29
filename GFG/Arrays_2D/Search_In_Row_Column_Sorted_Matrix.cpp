// TC: O(m + n)
// SC: O(1)

bool matSearch(const vector<vector<int>>& arr, int x) {
    int m = arr.size();
    int n = arr[0].size();

    int i = 0, j = n - 1;

    // O(m + n)
    while (i < m && j >= 0) {
        if (arr[i][j] == x)
            return true;          // O(1)
        else if (arr[i][j] < x)
            i++;                  // O(1)
        else
            j--;                  // O(1)
    }

    return false;
}

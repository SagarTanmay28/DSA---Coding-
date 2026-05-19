// TC: O(m × n)
// SC: O(1)

void setMatrixZeroes(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    bool zerothRow = false;
    bool zerothCol = false;

    // O(n)
    for (int j = 0; j < n; j++) {
        if (arr[0][j] == 0) {
            zerothRow = true;
            break;
        }
    }

    // O(m)
    for (int i = 0; i < m; i++) {
        if (arr[i][0] == 0) {
            zerothCol = true;
            break;
        }
    }

    // O(m × n)
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    // O(m × n)
    for (int i = 1; i < m; i++) {
        if (arr[i][0] == 0) {
            for (int j = 1; j < n; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // O(m × n)
    for (int j = 1; j < n; j++) {
        if (arr[0][j] == 0) {
            for (int i = 0; i < m; i++) {
                arr[i][j] = 0;
            }
        }
    }

    // O(n)
    if (zerothRow) {
        for (int j = 0; j < n; j++) {
            arr[0][j] = 0;
        }
    }

    // O(m)
    if (zerothCol) {
        for (int i = 0; i < m; i++) {
            arr[i][0] = 0;
        }
    }
}

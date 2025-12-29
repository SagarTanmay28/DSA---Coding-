// TC: O(n)
// SC: O(n)

vector<int> nthRowOfPascalTriangle(int n) {

    vector<int> row(n, 1);   // O(n)

    // O(n)
    for (int i = 2; i < n; i++) {

        // O(n)
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];   // O(1)
        }
    }

    return row;
}

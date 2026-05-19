// TC: O(m × n)
// SC: O(m × n)

vector<int> spirallyTraverse(const vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    vector<int> ans;

    int minr = 0, maxr = m - 1;
    int minc = 0, maxc = n - 1;

    // O(m × n)
    while (minr <= maxr && minc <= maxc) {

        // O(n) → top row
        for (int j = minc; j <= maxc; j++) {
            ans.push_back(arr[minr][j]);   // O(1)
        }
        minr++;
        if (minr > maxr || minc > maxc) break;

        // O(m) → right column
        for (int i = minr; i <= maxr; i++) {
            ans.push_back(arr[i][maxc]);   // O(1)
        }
        maxc--;
        if (minr > maxr || minc > maxc) break;

        // O(n) → bottom row
        for (int j = maxc; j >= minc; j--) {
            ans.push_back(arr[maxr][j]);   // O(1)
        }
        maxr--;
        if (minr > maxr || minc > maxc) break;

        // O(m) → left column
        for (int i = maxr; i >= minr; i--) {
            ans.push_back(arr[i][minc]);   // O(1)
        }
        minc++;
    }

    return ans;
}

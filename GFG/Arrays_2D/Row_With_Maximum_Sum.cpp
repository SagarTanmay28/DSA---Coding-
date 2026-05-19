// TC: O(m × n)
// SC: O(1)

int rowWithMaxSum(const vector<vector<int>>& arr) {

    // O(m)
    for (int i = 0; i < arr.size(); i++) {

        int sum = 0;

        // O(n)
        for (int val : arr[i]) {
            sum += val;
        }

        // O(1)
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    return maxRow;
}

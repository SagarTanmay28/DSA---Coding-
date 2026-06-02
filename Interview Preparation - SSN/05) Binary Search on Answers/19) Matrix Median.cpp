Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.



class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX, high = INT_MIN;

        // Find min and max element in matrix
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int required = (n * m) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            // Count elements <= mid
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count <= required)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};


count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();

Matrix:

[
 [1, 3, 5],
 [2, 6, 9],
 [3, 6, 9]
]

Suppose during binary search:

mid = 5

We want to count how many numbers are ≤ 5.

What upper_bound() does

upper_bound(start, end, x) returns an iterator pointing to the first element greater than x.

So:

upper_bound(row.begin(), row.end(), 5)

means:

Find the first element > 5

Row 1: [1, 3, 5]

Searching:

upper_bound([1,3,5], 5)

There is no element greater than 5, so it returns:

end()

Visual:

Index:   0   1   2
Value:  [1,  3,  5]
                    ^
                 returned iterator

Now:

upper_bound(...) - row.begin()

becomes:

3 - 0 = 3

Meaning:

3 elements are ≤ 5

Row 2: [2, 6, 9]
upper_bound([2,6,9], 5)

First element > 5 is:

6

Visual:

Index:   0   1   2
Value:  [2,  6,  9]
             ^

Subtract iterator positions:

1 - 0 = 1

Meaning:

1 element ≤ 5

(only 2)

Row 3: [3, 6, 9]

Again:

upper_bound([3,6,9], 5)

First element > 5:

6

Result:

1 - 0 = 1

Meaning:

1 element ≤ 5

(only 3)

Total count
count = 3 + 1 + 1 = 5

So there are 5 numbers ≤ 5 in the matrix.

Think of it like this:

[1, 3, 5]  -> 3 elements <= 5
[2, 6, 9]  -> 1 element <= 5
[3, 6, 9]  -> 1 element <= 5
------------------------------
Total      -> 5

Why subtract?

Because iterators act like pointers.

Example:

row.begin() -> index 0
upper_bound -> index 1

So:

iterator_at_1 - iterator_at_0 = 1

You are given an integer length and a 2D array updates, where:

length is the size of an initially zero-filled array.
Each update is of the form [startIndex, endIndex, inc].

For every update:

Add inc to every element in the range [startIndex, endIndex] (inclusive).

Return the final modified array after performing all the updates.


Input:
length = 5
updates = [[1,3,2],[2,4,3],[0,2,-2]]

Output:
[-2,0,3,5,3]

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);

        for (auto &u : updates) {
            int l = u[0];
            int r = u[1];
            int x = u[2];

            arr[l] += x;
            if (r + 1 < length)
                arr[r + 1] -= x;
        }

        for (int i = 1; i < length; i++)
            arr[i] += arr[i - 1];

        return arr;
    }
};

class Solution {
public:
    // Function to rotate an array by k elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n;

        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        reverse(arr, 0, n - 1);
    }

private:
    void reverse(vector<int>& arr, int i, int j) {
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

class Solution {
public:
    // Function for adding one to the number represented by the array
    vector<int> addOne(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] + carry <= 9) {
                ans.push_back(arr[i] + carry);
                carry = 0;
            } else {  // arr[i] + carry == 10
                ans.push_back(0);
                carry = 1;
            }
        }

        if (carry == 1)
            ans.push_back(1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

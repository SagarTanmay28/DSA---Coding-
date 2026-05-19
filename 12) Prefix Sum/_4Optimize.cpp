#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);  // Initialize the result array with 1s

    // Calculate prefix products and store in result
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix products and multiply with prefix products in result
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    // Print the original array
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    vector<int> result = productExceptSelf(nums);

    // Print the result array
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

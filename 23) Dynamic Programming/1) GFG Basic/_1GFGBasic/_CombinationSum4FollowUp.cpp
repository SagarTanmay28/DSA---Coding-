#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
int combinations(vector<int>& nums, int target, int& original, unordered_map<int, int>& dp){
    if(original >= 0 && target < 0) return 0;
    if(original < 0 && target > 0) return 0;

    if(target == 0) return 1;
    if(dp.count(target)) return dp[target];

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        if(original < 0 && nums[i] > 0) continue;  // VIMP
        if(original > 0 && nums[i] < 0) continue;  // VIMP

        ans += combinations(nums,target-nums[i],original,dp);
    }
    return dp[target] = ans;
}
int main(){
    vector<int> nums = {-1,-2,3};
    int target = -4;
    sort(nums.begin(),nums.end());
    unordered_map<int, int> dp;

    cout << combinations(nums,target,target,dp);
}
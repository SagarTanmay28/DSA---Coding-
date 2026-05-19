#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i+=3){
            if((nums[i]!=nums[i+1]) || (nums[i]!=nums[i+2])) return nums[i];
        }
        return nums[n-1];
    }

int main(){
    vector<int> v={0,1,0,1,0,1,99};
    cout<<singleNumber(v);

}
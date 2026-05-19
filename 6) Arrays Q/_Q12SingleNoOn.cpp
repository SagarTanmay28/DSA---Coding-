#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        int i,j;
        for( i=0,j=1; i<n,j<n ;i+=2,j+=2){
            if(nums[i]!=nums[j]) return nums[i];
               
        }
        return nums[i];
    }

 int main(){
    vector<int> v={4,1,2,1,2};
    cout<<singleNumber(v);

}
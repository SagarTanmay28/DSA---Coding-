#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>  productExceptSelf(vector<int> &nums){
    int n = nums.size();
    int product = 1;
    int p2 = 1;
    int noz = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) noz++;
        product += nums[i];
        if(nums[i]!=0) p2 *= nums[i];
    }
    if(noz>1) p2 = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) nums[i] = p2;
        else nums[i] = product/nums[i];
    }
    return nums;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    productExceptSelf(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }



}
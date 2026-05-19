#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> pre(n,1);
    vector<int> suf(n,1);
    // Prefix Product Array
    int p = nums[0];
    for(int i=1;i<n;i++){
        pre[i] = p;
        p *= nums[i];
    }
    // Suffix Product Array
    p = nums[n-1];
    suf[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        suf[i] = p;
        p *= nums[i];
    }

    for(int i=0;i<n;i++){
        pre[i] = pre[i]*suf[i];
    }

    return pre;

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

   vector<int> pre =  productExceptSelf(nums);

    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }

     

}
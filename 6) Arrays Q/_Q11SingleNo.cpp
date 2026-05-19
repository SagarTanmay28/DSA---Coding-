#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> v(n,0);
       for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                v[i]++;
                v[j]++;
            }
       }
       }
        
       int x;
        for(int k=0;k<n;k++){
            if(v[k]==0){
                x=k;
                break;

            }
        }
        return nums[x];
    }

int main(){

    vector<int> v={4,1,2,1,2};
    cout<<singleNumber(v);

}
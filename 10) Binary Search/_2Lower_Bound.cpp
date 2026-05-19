#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int> arr,int target){
    int n = arr.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] >= target){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid + 1;
    }
    return ans;
    

}

int main(){
   // vector<int> nums = {1 ,2 ,8 ,10, 11, 12, 19};

    vector<int> nums = {1,2,4,5,9,15,18,21,24};
    int target = 12;
    cout<<lowerBound(nums,target);

}
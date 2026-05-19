#include<iostream>
#include<vector>
using namespace std;
int UpperBound(vector<int> arr,int target){
    int n = arr.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] > target){
            ans = mid;
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    return arr[ans];
}

int main(){
    vector<int> nums = {1,2,4,5,9,15,18,21,24};
    int target = 21;
    cout<<UpperBound(nums,target);

}
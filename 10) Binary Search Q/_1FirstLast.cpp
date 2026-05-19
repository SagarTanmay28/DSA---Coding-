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

int upperBound(vector<int> arr,int target){
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
    return ans;
}

vector<int> firstLast(vector<int> arr,int target){
    int lb = lowerBound(arr,target);
    if(lb == arr.size() || arr[lb] != target) return {-1 , -1};
    return {lb, upperBound(arr,target)-1};
}

int main(){
   // vector<int> nums = {1 ,2 ,8 ,10, 11, 12, 19};

    vector<int> nums = {1,2,2,3,3,3,3,3,4,4,5,8,9};
    int target = 3;
    cout<<lowerBound(nums,target)<<endl;
    cout<<upperBound(nums,target)<<endl;

    
    vector<int> result = firstLast(nums, target);
    cout << "First and Last Position: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;

}
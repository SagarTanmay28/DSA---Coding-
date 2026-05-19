#include<iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int> v, int target){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==target){
            if(v[mid+1]==target) lo = mid+1;
            else return mid;
        }
        else if(v[mid]<target) lo = mid + 1;
        else hi = mid - 1;
    }
}

int main(){
    vector<int> v = {1,2,2,3,3,3,3,3,4,4,5,8,9};
    int target = 3;
    cout<<lastOccurence(v,target);
}

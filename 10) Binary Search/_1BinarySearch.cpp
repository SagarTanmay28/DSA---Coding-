#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> v,int target){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==target) return mid;
        else if(v[mid]<target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1 ;

}
int main(){
    vector<int> v = {-1,0,3,5,9,12};
    int target = 9;
    cout<<search(v,target);
}
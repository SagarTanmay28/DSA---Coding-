#include<iostream>
#include<vector>
using namespace std;
int smallestMissingPositive(vector<int> v){
      int n  = v.size();
      int lo = 0;
      int hi = n-1;
      int ans = -1;
      while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==mid) lo = mid + 1;
        else{
            ans = mid;
            hi = mid - 1;
        }
      }
      return ans;
}

int main(){
    vector<int> v = {0,1,3,4,6,8,9};
     cout<<smallestMissingPositive(v);
 }
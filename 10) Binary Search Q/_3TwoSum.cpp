#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> twoSum(vector<int> &v,int target){
    int n = v.size();
    for(int i=0;i<n;i++){
        int complement = target - v[i];
        int lo = i+1;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid]==complement){
                v.push_back(i+1);
                v.push_back(mid+1);
                break;
            }
            else if(v[mid]>complement) hi = mid - 1;
            else lo = mid + 1;
        }
        return v;
    }
    
}
int main(){
    vector<int> v={2,7,11,15};
    int target = 9;
    twoSum(v,target);
    cout<<v[0]<<" "<<v[1];
    

}
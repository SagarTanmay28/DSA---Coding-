#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v1, vector<int> &v2, vector<int> &ans){
    int i = 0;
    int j = 0;
    int k = 0;
    while( i<v1.size() && j<v2.size() ){
         if(v1[i]<v2[j]) ans[k++]=v1[i++];
         else ans[k++]=v2[j++];
    }
    if(i==v1.size()) while(j<v2.size()) ans[k++]=v2[j++];
    if(j==v2.size()) while(i<v1.size()) ans[k++]=v1[i++];
}

int main(){
    int arr[] = {2,3,5,7};
    int brr[] = {3,4,6,8,9,10,11};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(brr)/sizeof(brr[0]);
    vector<int> v1(arr,arr+m);
    vector<int> v2(brr,brr+n);
    vector<int> ans(m+n);
    merge(v1,v2,ans);
    for(int i=0;i<m+n;i++){
        cout<< ans[i] << " ";
    }
}
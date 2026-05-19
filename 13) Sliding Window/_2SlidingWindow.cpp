#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxSum = INT_MIN;
    int maxIdx = -1;
    int sum = 0;
    for(int i=0;i<k;i++){
       sum += arr[i];
    } 
    
    int i = 1;
    int j = k;
   
    while(j<n){
       sum = sum + arr[j] - arr[i-1];
      if(sum>maxSum){
        maxSum = sum;
        maxIdx = i;
      }

      i++;
      j++;
      
    }

    cout<<maxSum<<endl;
    cout<<maxIdx;
    

}
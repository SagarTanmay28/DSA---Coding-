#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[] = {1,1,6,7,77,88,32,-1,0,7};
    int n = sizeof(arr)/4; // 4 because of int
    int k = 4;

    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }

    cout << pq.top();

}
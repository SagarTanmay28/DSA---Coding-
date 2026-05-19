#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[6] = {4,2,3,5,6,7};
    int* ptr = arr; // address point out kar raha hai 
    cout<<ptr<<endl;
    ptr[0] = 8;
    for(int i=0;i<6;i++){
        cout<<ptr[i]<<" ";
    }
    // ptr got the address of an array so 
    // ptr have full power to change or modify the given array 
   
   cout<<endl;

   vector<int> v;
   v.push_back(6);
   v[1] = 1;
   v.push_back(2);
   v.push_back(4);

   for(int i=0;i<4;i++){
    cout<<v[i]<<" ";
   } 
   // 6 2 4 0 here 0 is the garbage value 



}
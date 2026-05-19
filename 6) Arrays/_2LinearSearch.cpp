#include<iostream>
using namespace std;
int main(){

   int n;
   cin>>n;
   
   int arr[n];

   for(int i=0;i<n;i++){
    cin>>arr[n];
   }

    int x;
   cin>>x;

  bool flag = false;
  for(int i=0;i<n;i++){
     if(arr[i]==x) flag = true;
  }
  if(flag==true) cout<<"yes";
  else cout<<"no";
}
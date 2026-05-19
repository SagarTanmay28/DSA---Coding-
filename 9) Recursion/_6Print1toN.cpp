#include<iostream>
using namespace std; 
// with extra parameter
void print(int i, int n){
    // base case
    if(i>n) return;
    cout<<i<<endl;
    print(i+1,n);
}

// without parameter 
void print2(int n){
    int i =1;
    while(i<=n){
        cout<<i<<endl;
        i++;
    }

}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    print(1,n);
}
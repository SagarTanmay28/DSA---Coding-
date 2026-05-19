#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

void fun(){
  int x=2;
  int idx=-1;

    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
          idx=i;
        break;
        } 
    }

    cout<<idx;
}


int main(){ 

int n;
cin>>n;

for(int i=0;i<n;i++){
int j;
cin>>j;
v.push_back(j);
}

 fun();
  
}

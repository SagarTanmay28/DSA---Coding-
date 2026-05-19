#include<iostream>
using namespace std;
int main(){
    char str[6] = {'a','b','c','d','e'}; 
    

    
    for(int i=0;str[i]!='\0';i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    cout<<str;
    cout<<endl;

    cout<< (int)(str[5]);
}
// strings are basically char arrays
// char ch ='\'  \ not allowed character 
// char ch ='\0'its null character
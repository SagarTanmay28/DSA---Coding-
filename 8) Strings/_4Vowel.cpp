#include<iostream>
#include<string>
using namespace std;
int main(){
    string s ="Tanmay";

    int count =0;
    int i=0;
    while(s[i]!='\0'){
           
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
              count++;
            }
            i++;
        
        }
        cout<<count;
        cout<<endl;
        

    // updation 
    // in C++ , Strings are mutable but not in Java
    s[1] = 'j';
    cout<<s;

}
    

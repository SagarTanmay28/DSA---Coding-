#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "1111111";// n = 5
    int n = s.size();
   
    string s1;
    for(int i=0;i<=n/2;i++){
        s1 += s[i];
    }

    string s2;
    for(int i=n-1;i>=n/2;i--){
        s2 += s[i];
    }

    if(n%2==0) cout<<"Not a Palindrome";
    else if(s1==s2) cout<<"Palindrome";
    else cout<<"Not a Palindrome";
    

    



}
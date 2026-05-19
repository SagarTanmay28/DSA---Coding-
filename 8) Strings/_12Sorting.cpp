#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s;
    // spaces pahile print hotat karan he sagl 
    // depends on ascii values and not on alphabets 
}
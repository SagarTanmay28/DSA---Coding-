#include<iostream>
using namespace std;
int main(){
    string s = "Dhoni";
    string t = "CSK";
    string ans = "";
    cout<<ans + s[0];
    cout<<endl;

    cout<<s<<endl;
    s.push_back('7');
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;

    s = s + t;
    cout<<s<<endl;
    s = s + "Ruturaj";
    cout<<s<<endl;
    s = "Ruturaj" + t;
    cout<<s<<endl;
}
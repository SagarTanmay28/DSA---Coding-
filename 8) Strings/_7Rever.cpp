#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s = "abcdefghij";
    
    int n = s.length();
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    reverse(s.begin()+2,s.end());
    cout<<s<<endl;
    reverse(s.begin()+2,s.end()-1);
    cout<<s<<endl;

    string t = "abcdefghij";
    cout<<t<<endl;
    reverse(t.begin()+2,t.begin()+5); // +5 aahe but 4 paryantch reverse hot 1 jast lihaych asa asl tar
    cout<<t<<endl;

}
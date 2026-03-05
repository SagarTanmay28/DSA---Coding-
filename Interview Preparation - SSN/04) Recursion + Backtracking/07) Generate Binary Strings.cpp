#include<iostream>
#include<string>
using namespace std;

void generate(string s, int n){
    if(s.size() == n){
        for(int i=0;i<s.size();i++) cout << s[i];
        cout << endl;
        return;
    }
    generate(s+'0',n);
    if(s == "" || s[s.size()-1] != '1') generate(s+'1',n);
}

int main(){
    int n = 3;
    generate("",n);
}

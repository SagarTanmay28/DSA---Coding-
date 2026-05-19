#include<iostream>
#include<string>
using namespace std;
void removeChar(string ans, string original){
    if(original.length()==0){
        cout<<ans;
        return;
    } // Base Case
    char ch = original[0];
    if(ch=='a') removeChar(ans,original.substr(1));
    else removeChar(ans+ch,original.substr(1));
}

int main(){
    string str = "Ganpati Bappa";
    removeChar("",str);
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        string s ="";
        for(int i=0;i<=h-n;i++){
            if(haystack[i]==needle[0]){
                s += haystack.substr(i,n);
                if(s==needle) return i;
                else s="";
            }  
        }
        return -1;
    }
int main(){
    string haystack = "sadbutsad";
    string needle = "sad";
    cout<<needle.substr(0,3)<<endl;
    strStr(haystack,needle);
    cout<<strStr;
}
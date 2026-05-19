#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


string reverseWords(string s) {
    
stringstream ss(s);
       string temp;
       vector<string> v;
       while(ss>>temp){
        v.push_back(temp);
       }
       reverse(v.begin(),v.end());
       string rev;
       for(int i=0;i<v.size();i++){
        rev += v[i] + " ";
       }
       string Rev;
       Rev = rev.substr(0,rev.size()-1);

       cout<<Rev;
}

    int main(){
    string s;
    getline(cin,s);
   
    reverseWords(s);

}
   
      
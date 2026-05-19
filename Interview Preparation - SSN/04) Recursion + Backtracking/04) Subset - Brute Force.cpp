// String
#include<iostream>
#include<string>
using namespace std;
void printSubset(string ans, string original){
    if(original==""){
        cout<<ans<<endl;
        return;
    }
    char ch = original[0];
    printSubset(ans+ch,original.substr(1));
    printSubset(ans,original.substr(1));
}

int main(){
    string str = "abc";
    printSubset("",str);
}

// Vector 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void storeSubset(string ans, string original, vector<string>& v){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    storeSubset(ans,original.substr(1),v);
    storeSubset(ans+ch,original.substr(1),v);
}

int main(){
    string str = "abc";
    vector<string> v;
    storeSubset("",str,v);
    for(string ele : v){
        cout<<ele<<endl;
    }

} 

// Array 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printSubset(int arr[], int n, int idx, vector<int> ans){ // ith &ans nahi lihaych karan nantar te vector sobat add add hot jaat subset seperately yet nahit
    if(idx==n){
       for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
       }
       cout<<endl;
       return;
    }
    
    printSubset(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    printSubset(arr,n,idx+1,ans);
}

int main(){
    
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubset(arr,n,0,v);

}

#include<iostream>
#include<unordered_map> 
#include<algorithm>
using namespace std;
int main(){
    pair<string,int> p;
    p.first = "MS DHONI";
    p.second = 7;
    cout << p.first << " " << p.second << endl;

    unordered_map<string,int> m; // string -> key & int -> value
    // Method - 1
    pair<string,int> p1;
    p1.first = "Virat Kohli";
    p1.second = 18;
    m.insert(p1);

    for(pair<string,int> p : m){
        cout << p.first << " " << p.second << endl;
    }

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }

    // Method - 2

    m["Suresh Raina"] = 3;

    m.erase("Virat Kohli");

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }

    int nums[] = {2,5,10,2435,3};
    int n = sizeof(nums)/sizeof(nums[0]);
    int mx = *max_element(nums,nums+n);
    cout << mx;
    



}
#include<iostream> 
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(4);
    s.insert(1);
    s.insert(5);

    cout << s.size() << endl;
    s.erase(3);
    cout << s.size() << endl;

    int target = 4;
    if(s.find(target) != s.end()) cout<<"Exists"<<endl; // To Find we have to remember the syntax of this 
    else cout<<"Not Exists";

    // for each loop 
    for(int ele : s){
       cout << ele << " ";
    }
}
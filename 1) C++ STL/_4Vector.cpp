#include<iostream>
#include<vector>
using namespace std;

void vectors(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // emplace is faster than push back

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);  // see the Syntax Difference here 
    
    vector<int> v1; // {};
    vector<int> v1(5); // {0,0,0,0,0};
    vector<int> v1(5,100); // {100,100,100,100,100};
    vector<int> v2(v1);

    // 2D Vectors
    vector <vector<int>> v;
    vector <vector<int>> v(5);
    vector <vector<int>> v(5,vector<int> (3)); // 5 vectors and 3 -> each vectors size 
    vector <vector<int>> v(5,vector<int> (3,4));
    
    

}
int main(){
    vectors();
    // Input Vector
    vector<int> v;
    for(int i=0;i<5;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
}
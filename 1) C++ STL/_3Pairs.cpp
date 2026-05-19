#include<iostream>
using namespace std;

void pairs(){
    pair<int,int> p = {1,3}; // any data type will be used in place of int
    cout << p.first << " " << p.second << endl;

    pair<int,pair<int,int>> p1 = {1,{3,4}};
    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    pair<int,int> arr[] = { {1,2},{3,4},{5,6} };
    cout << arr[1].second;

}
int main(){
    pairs();
}
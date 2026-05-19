#include<iostream>
#include<vector>
using namespace std;

vector rotate(vector<vector<int>> &v){
    int n = v.size();
    // transpose
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // swap 
            int temp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = temp;
        }
    }
    return v;
}
int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);

    vector<int> v3;
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);


     vector =  rotate(v);

    

        
    }

    





#include<iostream>
using namespace std;
int power(int x, int y){
    int p = 1;
    
    for(int i=1;i<=y;i++){
        p *= x;
    }
    return p;
}
int main(){
    int x,y;
    cin >> x;
    
    cin >> y;
    cout << power(x,y);
}
#include<iostream>
using namespace std;
int maze(int row, int col){
    if(row<1 || col<1) return 0;
    if(row==1 && col==1) return 1;
    int Rightways = maze(row,col-1); // Right
    int Downways = maze(row-1,col); // Down
    int Totalways = Rightways + Downways;
    return Totalways;
}
int main(){
    cout<<maze(3,3);
}
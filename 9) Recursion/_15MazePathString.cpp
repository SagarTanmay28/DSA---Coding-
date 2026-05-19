#include<iostream>
using namespace std;

void printPath(int sr, int sc, int ec, int er, string s){
     if(sr>er || sc>ec) return;
    if(sr==er && sc==ec){ // destination reached
        cout<<s<<endl;
        return;
    }
    printPath(sr,sc+1,er,ec,s+'R');
    printPath(sr+1,sc,er,ec,s+'D');

}
int main(){
    printPath(1,1,3,3,"");
}
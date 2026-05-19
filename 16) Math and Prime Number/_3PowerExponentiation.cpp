#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
double power(double x, int n){
    double ans = 1;
        long long m = n;
        
        if(m<0){
            x = 1/x;
            m = -m;
        }
        while(m>0){
            if(m%2 == 1){
                ans = ans * x;
                m = m - 1;
            }
            else{
                m = m / 2;
                x = x * x;
            }
        }
       
        return ans;
        
}
int main(){
    double x = 2.5;
    double n = 10;
    double ans = power(x,n);
    cout << ans << endl;
}
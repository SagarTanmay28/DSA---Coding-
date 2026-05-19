                                
#include <iostream>
#include <algorithm>

using namespace std;

int findGcd1(int n1, int n2) {
    
    for(int i = min(n1, n2); i > 0; i--) {
    
        if(n1 % i == 0 && n2 % i == 0) {
           
            return i;
        }
    }
   
    return 1;
}

int findGcd2(int a, int b) {
    if(a == 0) return b;
    else return findGcd2(b % a, a);
}


int main() {
    int n1 = 20, n2 = 15;
    int n3 = 20, n4 = 15;
    
    // Find the GCD of n1 and n2
    int gcd1 = findGcd1(n1, n2);
    int gcd2 = findGcd2(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd1 << endl;
    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd2 << endl;

    return 0;
}


                                
                            
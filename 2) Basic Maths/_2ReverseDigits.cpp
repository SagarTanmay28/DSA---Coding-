                            
#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int revNum = 0;
	
	while(n > 0){
		
		int ld = n % 10;
		// Multiply the current reverse number
		// by 10 and add the last digit.
		revNum = (revNum * 10) + ld;
		// Remove the last digit from 'n'.
		n = n / 10;
	}
	// Print the reversed number.
	cout << revNum;
}
                            
                        
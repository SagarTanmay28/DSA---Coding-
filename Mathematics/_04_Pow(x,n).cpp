/*
T.C = O(log n);
S.C = O(1);
*/
class Solution {
public:
    double fastPow(double x, long long n) {
        double res = 1.0;

        while (n > 0) {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        long long N = n;   // avoid overflow
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};

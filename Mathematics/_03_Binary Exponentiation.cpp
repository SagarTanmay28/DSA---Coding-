TC: O(log b)
SC: O(1)
🔥 Best for most problems

long long binExp(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}


***********************************************************************************_Binary Exponentiation with Modulo (%)_*********************************************************************************************

// TC: O(log n)
// SC: O(1)
// Binary Exponentiation / Fast Power

const long long MOD = 1e9 + 7;

long long modPow(long long x, long long n) {
    long long ans = 1;

    x %= MOD;

    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * x) % MOD;
        }

        x = (x * x) % MOD;
        n /= 2;
    }

    return ans;
}


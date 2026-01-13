TC: O(log m)
SC: O(1)
🔥🔥 CP standard (MOD = 1e9+7)

Only when m is prime

𝑎^(-1) = a^(m-2) % m

code -> 

long long binExpMod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long a, long long m) {
    return binExpMod(a, m - 2, m);
}

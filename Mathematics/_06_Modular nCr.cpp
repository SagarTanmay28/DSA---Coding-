TC:

Precompute: O(n)

Query: O(1)

SC: O(n)
🔥🔥 Best CP solution


const long long MOD = 1e9 + 7;
const int MAXN = 1e6;

long long fact[MAXN + 1], invFact[MAXN + 1];

long long binExpMod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[MAXN] = binExpMod(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

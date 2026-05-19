TC: O(√n)
SC: O(1)

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * 1LL * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

****************************************************************************************************Competitive Programming********************************************************************************************
TC: O(√n) (fewer iterations)
SC: O(1)
🔥 Used in CP & contests

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * 1LL * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

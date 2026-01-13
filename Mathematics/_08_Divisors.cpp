int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * 1LL * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}


Method 4: Divisors Using Prime Factorization

🔹 Advanced CP

int countDivisors(int n) {
    int res = 1;
    for (int i = 2; i * 1LL * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    return res;
}

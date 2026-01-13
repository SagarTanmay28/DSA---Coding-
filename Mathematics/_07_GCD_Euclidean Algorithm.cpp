
GCD formula:

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


🔥 CP Tip

LCM formula:

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

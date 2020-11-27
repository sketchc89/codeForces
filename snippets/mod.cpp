#include <bits/stdc++.h>

using namespace std;

// constexpr static int64_t BIG_PRIME = 998244353;

int64_t subtractMod(int64_t a, int64_t b, int64_t mod) {
    auto res = (a - b) % mod;
    if (res < 0) {
        res += mod;
    }
    return res;
}

int64_t addMod(int64_t a, int64_t b, int64_t mod) {
    return (a + b) % mod;
}

int64_t multMod(int64_t a, int64_t b, int64_t mod) {
    return (a * b) % mod;
}

int64_t multModSafe(int64_t a, int64_t b, int64_t mod) {
    return ((a % mod) * (b % mod)) % mod;
}

int64_t binPowMod(int64_t base, int64_t exp, int64_t mod) {
    int64_t res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = multMod(res, base, mod);
        }
        base = multMod(base, base, mod);
        exp /= 2LL;
    }
    return res;
}

int64_t divMod(int64_t a, int64_t b, int64_t mod) {
    return multMod(a, binPowMod(b, mod - 2LL, mod), mod);
}

int main() {
    return 0;
}

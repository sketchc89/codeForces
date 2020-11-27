#include <bits/stdc++.h>

using namespace std;

constexpr static int64_t BIG_PRIME = 998244353;
int64_t fibMod(int64_t n, int64_t mod) {
    if (n <= 1) {
        return 1;
    }
    int64_t prevPrev = 1;
    int64_t prev = 1;
    int64_t curr;
    for (int64_t i = 2; i <= n; ++i) {
        curr = (prev + prevPrev) % mod;
        prevPrev = prev;
        prev = curr;
    }
    return curr;
}

int64_t multMod(int64_t a, int64_t b, int64_t mod) {
    return (a * b) % mod;
}

int64_t binPowMod(int64_t base, int64_t exp, int64_t mod) {
    int64_t res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = multMod(res, base, mod);
        }
        base = multMod(base, base, mod);
        exp /= 2;
    }
    return res;
}

int64_t radioTowers(int64_t cities) {
    int64_t x = fibMod(cities - 1LL, BIG_PRIME);
    int64_t y = binPowMod(2, cities, BIG_PRIME);
    int64_t yInv = binPowMod(y, BIG_PRIME - 2LL, BIG_PRIME);
    return multMod(x, yInv, BIG_PRIME);
}

int main() {
    int64_t cities;
    cin >> cities;
    int64_t res = radioTowers(cities);
    cout << res << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
constexpr static size_t NUM_PRIMES = 1000001;

namespace cf {
namespace primes {


array<bool, NUM_PRIMES> sieveArr;

void sieve() {
    sieveArr.fill(true);
    sieveArr[0] = false;
    sieveArr[1] = false;
    for (i64 i = 2; i < sieveArr.size(); ++i) {
        if (sieveArr[i]) {
            for (i64 j = i * i; j < sieveArr.size(); j += i) {
                sieveArr[j] = false;
            }
        }
    }
}
void primeStats(i64 val, unordered_map<i64, i64>& count, map<i64, unordered_set<i64>>& freq, array<bool, NUM_PRIMES>& primes) {
    for (i64 i = 2; i <= sqrt(val); ++i) {
        if (!primes[i]) {
            continue;
        }
        i64 temp = val;
        while (temp % i == 0) {
            temp /= i;
            count[i]++;
        }
    }
    for (auto&& kv : count) {
        freq[kv.second].insert(kv.first);
    }
}
}
}


int main() {

    unordered_map<i64, i64> primeCount;
    map<i64, unordered_set<i64>> primeFreq;
    cf::primes::sieve();
    cf::primes::primeStats(5428, primeCount, primeFreq, cf::primes::sieveArr);
    for (i64 i = 0; i < cf::primes::sieveArr.size(); ++i) {
        if (cf::primes::sieveArr[i]) {
            cout << i << ' ';
        }
    }
    return EXIT_SUCCESS;
}

#include <bits/stdc++.h>
using namespace std;
constexpr static size_t NUM_PRIMES = 1000001;

namespace cf {
namespace primes {


array<bool, NUM_PRIMES> sieveArr;

void sieve() {
    sieveArr.fill(true);
    sieveArr[0] = false;
    sieveArr[1] = false;
    for (int64_t i = 2; i < sieveArr.size(); ++i) {
        if (sieveArr[i]) {
            for (int64_t j = i * i; j < sieveArr.size(); j += i) {
                sieveArr[j] = false;
            }
        }
    }
}
void primeStats(
        int64_t val,
        unordered_map<int64_t, int64_t>& count,
        map<int64_t, unordered_set<int64_t>>& freq,
        array<bool, NUM_PRIMES>& primes) {
    for (int64_t i = 2; i * i <= val; ++i) {
        if (primes[i] && val % i == 0) {
            while (val % i == 0) {
                count[i]++;
                val /= i;
            }
        }
    }
    if (val > 1) {
        count[val]++;
    }
    for (auto&& kv : count) {
        freq[kv.second].insert(kv.first);
    }
}
}
}


int main() {

    unordered_map<int64_t, int64_t> primeCount;
    map<int64_t, unordered_set<int64_t>> primeFreq;
    cf::primes::sieve();
    cf::primes::primeStats(5428, primeCount, primeFreq, cf::primes::sieveArr);
    for (int64_t i = 0; i < cf::primes::sieveArr.size(); ++i) {
        if (cf::primes::sieveArr[i]) {
            cout << i << ' ';
        }
    }
    return EXIT_SUCCESS;
}

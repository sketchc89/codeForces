#include <bits/stdc++.h>

using namespace std;

array<bool, 1000001> primes;
unordered_map<int64_t, int64_t> primeCount;
map<int64_t, unordered_set<int64_t>, greater<int64_t>> primeFreq;

void sieve() {
    primes.fill(true);
    primes[0] = false;
    primes[1] = false;
    for (int64_t i = 2; i < primes.size(); ++i) {
        if (primes[i]) {
            for (int64_t j = i * i; j < primes.size(); j += i) {
                primes[j] = false;
            }
        }
    }
}

void factorize(int64_t val) {
    for (int64_t i = 2; i <= sqrt(val); ++i) {
        if (primes[i] && val % i == 0) {
            int64_t temp = val;
            while (temp % i == 0) {
                primeCount[i]++;
                temp /= i;
            }
        }
    }
    for (auto&& kv : primeCount) {
        primeFreq[kv.second].insert(kv.first);
    }
    // cout << "\nFactorize " << val << ":\t";
    // for (auto&& kv : primeCount) {
    //     cout << kv.first << ':' << kv.second << '\t';
    // }
    // cout << '\n';
    // for (auto&& kv : primeFreq) {
    //     cout << "Freqency " << kv.first << ":\t";
    //     for (auto num : kv.second) {
    //         cout << num << ',';
    //     }
    //     cout << '\n';
    // }
}

int main() {
    int tests;
    cin >> tests;
    vector<vector<int64_t>> vi(tests);
    sieve();
    for (int test = 0; test < tests; ++test) {
        int64_t val;
        cin >> val;
        primeCount.clear();
        primeFreq.clear();
        factorize(val);
        vector<int64_t> res;
        int64_t freq = -1;
        int64_t factor = 1;
        if (primeCount.size() == 0) {
            vi[test].push_back(val);
            continue;
        }
        if (primeCount.size() == 1) {
            auto it = primeCount.begin();
            if (it->second == 1 && it->first * it->first != val) {
                vi[test].push_back(val);
                continue;
            }
        }
        for (auto it = primeFreq.begin(); it != primeFreq.end(); ++it) {
            int64_t cnt = next(it) == primeFreq.end() ? it->first : it->first - next(it)->first;
            for (auto num : it->second) {
                factor *= num;
            }
            for (int64_t n = 0; n < cnt; ++n) {
                res.push_back(factor);
            }
        }
        vi[test] = res;
    }
    for (auto&& test : vi) {
        cout << test.size() << '\n';
        for (auto num : test) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}

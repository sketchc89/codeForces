#include <bits/stdc++.h>
using namespace std;

constexpr static int64_t MOD = 1'000'000'007;

int main() {
    // i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    vector<int64_t> res(tests);

    for (int test = 0; test < tests; ++test) {
        int64_t N;
        cin >> N;
        vector<int64_t> vll(N);
        for (int i = 0; i < vll.size(); ++i) {
            cin >> vll[i];
        }

        vector<int64_t> count(62, 0);
        int64_t sum = 0;
        for (int bit = 0; bit < count.size(); ++bit) {
            for (int i = 0; i < vll.size(); ++i) {
                if (vll[i] & (1LL << bit)) {
                    ++count[bit];
                }
            }
        }

        for (int i = 0; i < vll.size(); ++i) {
            int64_t andVal = 0;
            int64_t orVal = 0;
            for (int bit = 0; bit < count.size(); ++bit) {
                int64_t powMod = (1LL << bit) % MOD;
                if (vll[i] & (1LL << bit)) {
                    andVal = (andVal + powMod * count[bit]) % MOD;
                    orVal = (orVal + powMod * N) % MOD;
                } else {
                    orVal = (orVal + powMod * count[bit]) % MOD;
                }
            }

            sum = (sum + andVal * orVal) % MOD;
        }
        res[test] = sum;
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}

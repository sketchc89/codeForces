#include <bits/stdc++.h>

using namespace std;

int64_t bounce(int64_t n, int64_t p, int64_t k, int64_t addTime, int64_t removeTime, bitset<10000>& platform) {
    // cout << p << '\n';
    // for (int i = 0; i < n; ++i) {
    //     cout << platform[i];
    // }
    // cout << '\n';
    int64_t minCost = numeric_limits<int64_t>::max();
    for (int64_t shift = 0; shift < k; ++shift) {
        // cout << "Shift: " << shift << '\n';
        // for (int i = 0; i < n - shift; ++i) {
        //     cout << platform[i];
        // }
        // cout << '\n';
        int64_t missing = 0;
        if (p + shift >= n) {
            break;
        }
        for (int i = p; i < n - shift; i += k) {
            // cout << i << ':' << platform[i] << '\t';
            if (!platform[i]) {
                ++missing;
            }
        }
        // cout << "Shift: " << shift << '\t' << "missing: " << missing << '\n';
        auto cost = shift * removeTime + missing * addTime;
        minCost = min(minCost, cost);
        platform >>= 1;
    }

    return minCost;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t n, initDist, period, removeTime, addTime;
        cin >> n >> initDist >> period;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        // if (s.size() < 10000) {
        //     s += string(10000 - s.size(), '0');
        // }
        bitset<10000> platform(s);
        cin >> addTime >> removeTime;
        vi[test] = bounce(n, initDist - 1, period, addTime, removeTime, platform);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        vector<int64_t> costs(n), qty(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> costs[i];
        }
        qty[0] = n;
        qty[1] = n;
        int64_t minTot = costs[0] * qty[0] + costs[1] * qty[1];
        int64_t minEven = costs[0];
        int64_t minEvenIdx = 0;
        int64_t minOdd = costs[1];
        int64_t minOddIdx = 1;
        int64_t total = minTot;

        // cout << "Total is now: " << total << '\n';
        for (int i = 2; i < n; ++i) {
            if (i % 2 == 0) {
                if (costs[i] < minEven) {
                    minEven = costs[i];
                    qty[i] = qty[minEvenIdx] - 1LL;
                    qty[minEvenIdx] = 1LL;
                    // cout << qty[i] << '*' << costs[minEvenIdx] << ',' << costs[i] << '\n';
                    total -= qty[i] * (costs[minEvenIdx] - costs[i]);
                    minEvenIdx = i;
                } else {
                    qty[minEvenIdx]--;
                    qty[i] = 1LL;
                    total += costs[i] - costs[minEvenIdx];
                }
            } else {
                if (costs[i] < minOdd) {
                    minOdd = costs[i];
                    qty[i] = qty[minOddIdx] - 1LL;
                    qty[minOddIdx] = 1;
                    // cout << qty[i] << '*' << costs[minOddIdx] << '-' << costs[i] << '\n';
                    total -= qty[i] * (costs[minOddIdx] - costs[i]);
                    minOddIdx = i;

                } else {
                    qty[minOddIdx]--;
                    qty[i] = 1LL;
                    total += costs[i] - costs[minOddIdx];
                }
            }
            // cout << "Total is now: " << total << '\n';
            minTot = min(minTot, total);
        }
        vi[test] = minTot;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

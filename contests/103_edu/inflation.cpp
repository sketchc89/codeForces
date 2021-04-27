#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        vi[test] = 0LL;
        int N;
        int64_t tot, k, inc;
        cin >> N >> k;
        cin >> tot;
        for (int i = 1; i < N; ++i) {
            cin >> inc;
            int64_t newTot = ceil(static_cast<double>(100LL * inc) / k);
            vi[test] = max(vi[test], newTot - tot);
            tot += inc;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

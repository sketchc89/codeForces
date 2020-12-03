#include <bits/stdc++.h>

using namespace std;

int64_t seqSwap(int64_t swapVal, const vector<int64_t>& vi) {
    int64_t N = vi.size();
    if (is_sorted(vi.begin(), vi.end()) || N <= 1) {
        return 0;
    }
    int64_t i = 0, swaps = 0;
    while (i < vi.size()) {
        if (i == N - 1) {
            if (vi[N - 1] >= vi[N - 2]) {
                // do nothing
                // ++i;
            } else if (swapVal >= vi[N - 2]) {
                ++swaps;
            } else {
                return -1;
            }
        }
        if (vi[i] >= vi[i + 1]) {
            if (swapVal <= vi[i + 1]) {
                ++swaps;
                swap(swapVal, vi[i]);
            } else {
                return -1;
            }
        }
        ++i;
    }
    return swaps;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<pair<int64_t, int64_t>> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t n, swapVal;
        cin >> n >> swapVal;
        vector<int64_t> inp(n);
        for (int64_t i = 0; i < n; ++i) {
            cin >> inp[i];
        }
        vi[test] = seqSwap(swapVal, inp);
    }
    for (auto num : vi) {
        cout << num.first << ' ' << num.second << '\n';
    }
    return 0;
}

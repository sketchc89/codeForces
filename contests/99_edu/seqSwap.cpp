#include <bits/stdc++.h>

using namespace std;

int64_t seqSwap(int64_t swapVal, vector<int64_t>& vi) {
    int64_t N = vi.size();
    if (is_sorted(vi.begin(), vi.end()) || N <= 1) {
        return 0;
    }
    int64_t i = 1, swaps = 0, swapsNeeded = 0;
    if (vi[0] > swapVal) {
        // cout << "Swap " << vi[0] << " with " << swapVal << '\n';
        ++swaps;
        swap(swapVal, vi[0]);
    }
    while (i < vi.size()) {
        if (vi[i - 1] > swapVal) {
            // cout << "Swap " << vi[i - 1] << " with " << swapVal << '\n';
            ++swaps;
            swap(swapVal, vi[i - 1]);
        }
        if (vi[i - 1] > vi[i]) {
            if (swapVal < vi[i]) {
                // cout << "Swap " << vi[i] << " with " << swapVal << '\n';
                ++swaps;
                swapsNeeded = swaps;
                swap(swapVal, vi[i - 1]);
            } else {
                // cout << "Fail early\n";
                return -1;
            }
        }
        ++i;
    }
    // cout << "Success!\n";
    return swapsNeeded;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
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
        cout << num << '\n';
    }
    return 0;
}

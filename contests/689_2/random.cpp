#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<double> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t n, m;
        cin >> n >> m;
        vector<int> arr(n), sfwd(n), maxIdx(n);
        sfwd[0] = true;
        cin >> arr[0];
        int lastUnsorted = arr[0];
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
            sfwd[i] = arr[i] > arr[i - 1] && sfwd[i - 1];
            if (arr[i] != i + 1) {
                lastUnsorted = max(lastUnsorted, arr[i]);
            }
        }
        int experiments;
        double probAllFail = 1.0;
        int numToSort;
        double prob;
        for (int i = 0; i < m; ++i) {
            cin >> numToSort;
            cin >> prob;
            if (numToSort < lastUnsorted) {
                continue;
            }

            probAllFail *= (1.0 - prob);
        }
        if (sfwd[n - 1]) {
            vi[test] = 1.0;
        } else {
            vi[test] = 1.0 - probAllFail;
        }
    }

    for (auto num : vi) {
        cout << fixed << setprecision(6) << num << '\n';
    }
    return 0;
}

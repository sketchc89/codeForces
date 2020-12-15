#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int test = 0; test < vi.size(); ++test) {
        int N;
        cin >> N;
        vector<int> pre(N);
        cin >> pre[0];
        for (int i = 1; i < N; ++i) {
            int val;
            cin >> val;
            pre[i] = pre[i - 1] + val;
        }
        // for each presum
        int minOps = N - 1;
        for (int i = 2; i <= N; ++i) {
            if (pre[N - 1] % i != 0) {
                // cout << "Skipping " << i << '\n';
                continue;
            }
            // cout << "Testing " << i << '\n';
            bool valid = true;
            int target = pre[N - 1] / i;
            int inc = target;
            int ops = 0, totalOps = 0;
            // cout << "\n\n";
            for (int j = 0; j < N; ++j) {
                // cout << j << ' ' << pre[j] << ' ' << target << ' ';
                if (pre[j] == target) {
                    target += inc;
                    totalOps += ops;
                    ops = 0;
                } else if (pre[j] > target) {
                    valid = false;
                    break;
                } else {
                    // cout << "\t operation";
                    ++ops;
                }
                // cout << "\n";
            }
            totalOps += ops;
            if (valid && totalOps < minOps) {
                minOps = totalOps;
                // cout << "Minops are " << minOps << '\n';
            }
        }
        vi[test] = minOps;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int test = 0; test < vi.size(); ++test) {
        int N, prevPrev, prev;
        cin >> N;
        cin >> prevPrev;
        cin >> prev;
        int res = 0;
        cout << '\n' << prev << '\t' << prevPrev << '\n';
        for (int i = 2; i < N; ++i) {
            int val;
            cin >> val;
            cout << "\nMax-min" << max(val, max(prevPrev, prev)) << '\t' << min(val, min(prevPrev, prev)) << '\n';
            if (max(val, max(prevPrev, prev)) - min(val, min(prevPrev, prev)) <= 2) {
                cout << res << '\n';
                ++res;
            }
            prevPrev = prev;
            prev = val;
        }
        vi[test] = res;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }


    return 0;
}

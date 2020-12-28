/*
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o
    int tests;
    cin >> tests;

    vector<vector<int64_t>> res(tests);
    for (int test = 0; test < tests; ++test) {
        int64_t N;
        cin >> N;
        vector<int64_t> a(N);
        int64_t evenSum = 0;
        int64_t oddSum = 0;

        // record even and odd sums
        for (int i = 0; i < a.size(); ++i) {
            cin >> a[i];
            if (i % 2 == 0) {
                evenSum += a[i];
            } else {
                oddSum += a[i];
            }
        }

        // if even sum is more then set odd to 1
        if (evenSum + (N + 1LL) / 2LL > oddSum + N / 2LL) {
            for (int i = 1; i < a.size(); i += 2) {
                a[i] = 1;
            }
        } else {  // otherwise set even to 1
            for (int i = 0; i < a.size(); i += 2) {
                a[i] = 1;
            }
        }
        res[test] = move(a);
    }
    for (auto&& v : res) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return EXIT_SUCCESS;
}

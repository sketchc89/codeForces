#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<vector<int>> vi(tests);
    for (int test = 0; test < vi.size(); ++test) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i += 2) {
            b[i] = a[i / 2];
            // cout << "set " << i / 2 << " to " << i << '\n';
            b[i + 1] = a[N - 1 - i / 2];
            // cout << "set " << N - 1 - i / 2 << " to " << i + 1 << '\n';
        }


        vi[test] = move(b);
    }
    for (auto&& v : vi) {
        for (auto num : v) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}

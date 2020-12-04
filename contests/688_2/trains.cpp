#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests, bot, left;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int i = 0; i < vi.size(); ++i) {
        cin >> bot >> left;
        int64_t val;
        int64_t res = 0;
        unordered_set<int64_t> vb;
        for (int64_t j = 0; j < bot; ++j) {
            cin >> val;
            vb.insert(val);
        }
        for (int64_t j = 0; j < left; ++j) {
            cin >> val;
            if (vb.find(val) != vb.end()) {
                ++res;
            }
        }
        vi[i] = res;
    }
    for (auto n : vi) {
        cout << n << '\n';
    }


    return 0;
}

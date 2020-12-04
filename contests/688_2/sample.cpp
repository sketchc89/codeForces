#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests, bot, left;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int i = 0; i < vi.size(); ++i) {
        cin >> bot >> left;
        int64_t res = 0;
        vector<int64_t> vb(bot);
        for (int64_t j = 0; j < vb.size(); ++j) {
            cin >> vb[j];
        }
        int idx = 0;
        for (int64_t j = 0; j < left; ++j) {
            cin >> val;
            while (idx < vb.size() && val < vb[idx]) {
                ++idx;
            }
            if (val == vb[idx]) {
                ++res;
            }
        }
        vi[test] = res;
    }


    return 0;
}

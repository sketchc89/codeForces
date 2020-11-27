/* WARNING: Wrong Answer */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t boxes;
        cin >> boxes;
        vector<int64_t> blocks(boxes);
        int64_t sum = 0;
        int64_t maxElem = 0;
        for (int box = 0; box < boxes; ++box) {
            cin >> blocks[box];
            sum += blocks[box];
            maxElem = max(maxElem, blocks[box]);
        }
        int64_t rem = sum % (boxes - 1);
        vi[test] = max(rem, maxElem);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

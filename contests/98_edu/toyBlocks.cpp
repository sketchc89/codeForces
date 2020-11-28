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
        int64_t sum = 0;
        int64_t maxElem = 0;
        int64_t block;
        for (int box = 0; box < boxes; ++box) {
            cin >> block;
            sum += block;
            maxElem = max(maxElem, block);
        }
        if (boxes == 2) {
            vi[test] = 0;
            continue;
        }
        int64_t origSum = sum;
        if (sum / (boxes - 1) < maxElem) {
            sum = maxElem * (boxes - 1);
        }
        while (sum % (boxes - 1) != 0) {
            ++sum;
        }
        vi[test] = sum - origSum;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

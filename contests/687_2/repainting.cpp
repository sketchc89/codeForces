#include <bits/stdc++.h>

using namespace std;

int64_t paint(const int ability, vector<int64_t>& houses, unordered_map<int, int>& counter) {
    int64_t minDays = numeric_limits<int64_t>::max();
    for (auto&& kv : counter) {
        size_t idx = 0;
        int64_t days = 0;
        auto color = kv.first;
        while (idx < houses.size()) {
            if (houses[idx] == color) {
                ++idx;
            } else {
                ++days;
                idx += ability;
            }
        }
        minDays = min(minDays, days);
    }
    return minDays;
}

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        unordered_map<int, int> counter;
        int64_t numHouses, ability, h;
        cin >> numHouses;
        vector<int64_t> houses(numHouses);
        cin >> ability;
        for (int i = 0; i < houses.size(); ++i) {
            cin >> h;
            houses[i] = h - 1;
            counter[h - 1]++;
        }
        vi[test] = paint(ability, houses, counter);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void fillVec(map<int, int>& dp) {
    dp[0] = 0;
    dp[1] = 1;
    int sum = 1, prevSum = 0, maxI = 0;
    for (int i = 1; sum < 1000001; ++i) {
        dp[sum] = 1 + dp[prevSum];
        prevSum = sum;
        sum += i;
    }
}

int64_t jumps(int val, map<int, int>& dp) {
    int64_t result = 0;
    auto lb = dp.lower_bound(val);
    if (lb == dp.end()) {
        //
    } else if (lb->first == val) {
        return lb->second;
    } else {
        result += lb->second;
        auto it = dp.find(2 * (lb->first - val));
        if (it == dp.end()) {
            ;
        }
    }
    return result;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> inp(tests);
    vector<int64_t> vi(tests);
    map<int, int> dp;
    fillVec(dp);
    for (int64_t test = 0; test < tests; ++test) {
        cin >> inp[test];
    }
    for (auto in : inp) {
        jump(in, dp);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

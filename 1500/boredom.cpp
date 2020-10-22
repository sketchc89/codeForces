#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, int> db;
    ostringstream oss;
    constexpr int N = 100002;
    auto counter = array<int64_t, N>{};
    auto dp = array<int64_t, N>{};

    int n = 0;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);

    counter.fill(0);
    copy_n(istream_iterator<int64_t>(cin), n, back_inserter(arr));
    for (auto num : arr) {
        counter[num]++;
    }

    if (counter.size() <= 1) {
        cout << 0;
        return 0;
    }

    dp[0] = 0;
    dp[1] = 0;
    for (int64_t i = 2; i < counter.size(); ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + counter[i - 1] * (i - 1));
    }

    cout << dp[N - 1];
    return 0;
}

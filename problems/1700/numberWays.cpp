#include <bits/stdc++.h>

using namespace std;

int64_t splitThreeWay(const vector<int64_t>& vi) {
    int N = vi.size();
    vector<int64_t> preSum(N);
    int64_t total = accumulate(vi.begin(), vi.end(), static_cast<int64_t>(0));
    if (total % 3 != 0) {
        return 0;
    }
    auto target = total / 3;

    int64_t numCuts = 0, cnt = 0;
    preSum[0] = vi[0];
    if (vi[0] == target) {
        ++numCuts;
    }
    for (int i = 1; i < N - 1; ++i) {
        preSum[i] = preSum[i - 1] + vi[i];
        if (preSum[i] == 2 * target) {
            cnt += numCuts;
        }
        if (preSum[i] == target) {
            ++numCuts;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sz;
    cin >> sz;
    vector<int64_t> vi(sz);
    for (int i = 0; i < sz; ++i) {
        cin >> vi[i];
    }
    cout << splitThreeWay(vi) << '\n';
    return 0;
}

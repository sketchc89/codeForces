#include <bits/stdc++.h>

using namespace std;

int64_t calcDiff(vector<int64_t>& vi) {
    int64_t res = 0, change = 0;
    for (int64_t i = 1; i < vi.size(); ++i) {
        int64_t diff = vi[0] - vi[i] - change;
        res += abs(diff);
        change += diff;
        // cout << change << '\t' << diff << '\t' << res << '\n';
    }
    return res;
}

int64_t suffix(vector<int64_t>& vi) {
    // for (int i = 0; i < vi.size(); ++i) {
    //     for (int j = 0; j < vi.size(); ++j) {
    //         //
    //     }
    // }
    int64_t maxElem = *max_element(begin(vi), end(vi));
    int64_t minElem = *min_element(begin(vi), end(vi));
    int64_t res = INT64_MAX;
    if (vi[0] == maxElem) {
        int64_t temp = vi[0];
        vi[0] = *max_element(begin(vi) + 1, end(vi));
        // cout << "Change " << temp << " to " << vi[0] << " = " << res << '\n';
        res = min(calcDiff(vi), res);
        vi[0] = temp;
    }
    if (vi[0] == minElem) {
        int64_t temp = vi[0];
        vi[0] = *min_element(begin(vi) + 1, end(vi));
        res = min(calcDiff(vi), res);
        // cout << "Change " << temp << " to " << vi[0] << " = " << res << '\n';
        vi[0] = temp;
    }
    int64_t temp = vi[0];
    vi[0] = vi[1];
    res = min(calcDiff(vi), res);
    vi[0] = temp;

    for (int64_t i = vi.size() - 1; i > 0; --i) {
        if (vi[i] == vi[i - 1]) {
            continue;
        }
        int64_t temp = vi[i];
        vi[i] = vi[i - 1];
        res = min(calcDiff(vi), res);
        // cout << "Change " << temp << " to " << vi[i] << " = " << res << '\n';
        vi[i] = temp;
    }
    // int64_t diffIdx = -1;
    // int64_t maxDiff = -2;
    // for (int64_t i = 1; i < vi.size(); ++i) {
    //     int64_t diff = 0;
    //     auto targetDiff = vi[0] - vi[i];
    //     for (int64_t j = i + 1; j < vi.size(); ++j) {
    //         diff += max(abs(targetDiff), abs(vi[i] - vi[j]));
    //     }
    //     diff = max(diff, targetDiff);
    //     cout << i << '\t' << diff << '\n';
    //     if (diff >= maxDiff) {
    //         diffIdx = i;
    //         maxDiff = diff;
    //     }
    // }
    // auto temp = vi[diffIdx];
    // vi[diffIdx] = vi[diffIdx - 1];
    // cout << "Change " << temp << " to " << vi[diffIdx] << " = " << res << '\n';
    // res = min(calcDiff(vi), res);
    return res;
}

int main() {
    int64_t tests, nums;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int i = 0; i < vi.size(); ++i) {
        cin >> nums;
        vector<int64_t> arr(nums);
        for (int j = 0; j < arr.size(); ++j) {
            cin >> arr[j];
        }
        vi[i] = suffix(arr);
    }
    for (auto n : vi) {
        cout << n << '\n';
    }


    return 0;
}

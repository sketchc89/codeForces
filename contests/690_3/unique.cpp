#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    array<int, 512> arr;
    arr.fill(0);
    map<int, int> possible;
    for (int i = 0; i < arr.size(); ++i) {
        int val = i;
        int dig = 1;
        int sum = 0;

        // cout << i << ":\t";
        int num = 0;
        while (val) {
            if (val & 1) {
                // cout << "adding " << dig << '\t';
                sum += dig;
                num *= 10;
                num += dig;
            }
            val >>= 1;
            ++dig;
        }
        // cout << "final sum: " << sum << " final num: " << num << '\n';
        auto it = possible.find(sum);
        if (it == end(possible)) {
            possible.insert({sum, num});
        } else {
            if (num < possible[sum]) {
                possible[sum] = num;
            }
        }
    }
    // for (auto num : possible) {
    //     cout << num << ',';
    //     cout << '\n';
    // }


    for (int test = 0; test < vi.size(); ++test) {
        int num;
        cin >> num;
        auto it = possible.find(num);
        if (it != end(possible)) {
            vi[test] = it->second;
        } else {
            vi[test] = -1;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }


    return 0;
}

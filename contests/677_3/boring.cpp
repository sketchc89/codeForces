#include <bits/stdc++.h>

using namespace std;

int boring(int val) {
    int res = 0;
    res += 10 * ((val % 10) - 1);
    int keys = 1;
    while (val) {
        res += keys;
        keys++;
        val /= 10;
    }
    return res;
}

int main() {
    int tests;
    cin >> tests;
    vector<int> vi(tests);
    for (int i = 0; i < tests; ++i) {
        int val;
        cin >> val;
        vi[i] = boring(val);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

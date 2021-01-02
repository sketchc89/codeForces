#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<int> res(tests);

    for (int test = 0; test < tests; ++test) {
        int N;
        cin >> N;
        map<int, int> count;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            count[x]++;
        }
        for (auto& kv : count) {
            if (kv.second > 1) {
                kv.second--;
                count[kv.first + 1]++;
            }
        }
        res[test] = count.size();
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}

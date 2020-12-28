#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int N;
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cin >> N;
        vector<pair<int, int>> ops;
        int num = N;
        /* Ceiling division x/y returns one if y > x
         * If we eliminate all of the numbers after 2 then we are left with the final number
         * The final number would take lg(N) steps if we just divided by 2
         * sqrt shrinks faster than lg(N) so keep the sqrt rounded up around to divide N
         * Keep the sqrt rounded up of that and so on.
         * Every sqrt takes one extra step. The maximum number doable in 5 steps is 2^32, 6 steps 2^64...
         * because we are continually raising to 1/2 power */
        while (num > 2) {
            int root = ceil(sqrt(num));
            for (int i = root + 1; i < num; ++i) {
                ops.emplace_back(make_pair(i, i + 1));
            }
            ops.emplace_back(make_pair(num, root));
            ops.emplace_back(make_pair(num, root));
            num = root;
        }

        cout << ops.size() << '\n';
        for (auto&& p : ops) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return EXIT_SUCCESS;
}

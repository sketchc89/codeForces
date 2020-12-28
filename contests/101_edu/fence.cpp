#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<string> res(tests);

    for (int test = 0; test < tests; ++test) {
        int numPosts, h;
        cin >> numPosts >> h;
        vector<int64_t> ground(numPosts);
        for (int i = 0; i < ground.size(); ++i) {
            cin >> ground[i];
        }
        int64_t lowestPossible = ground[0];
        int64_t highestPossible = ground[0];
        bool possible = true;
        // cout << string(30, '-') << '\n';
        // cout << "FENCE: " << test << '\n';
        // cout << string(30, '-') << '\n';
        for (int i = 1; i < ground.size(); ++i) {
            lowestPossible = lowestPossible - (h - 1);
            highestPossible = highestPossible + (h - 1);
            if (lowestPossible > highestPossible) {
                possible = false;
                break;
            }
            if (highestPossible < ground[i]) {
                possible = false;
                break;
            } else {
                lowestPossible = max(lowestPossible, ground[i]);
            }
            if (lowestPossible > ground[i] + (h - 1)) {
                possible = false;
                break;
            } else {
                highestPossible = min(highestPossible, ground[i] + (h - 1));
            }
            // cout << "Width = " << i << '\t';
            // cout << "lowestPossible: " << lowestPossible << '\t';
            // cout << "highestPossible: " << highestPossible << '\t';
            // cout << '\n';
        }
        if (possible && ground[numPosts - 1] <= highestPossible && ground[numPosts - 1] >= lowestPossible) {
            res[test] = "YES";
        } else {
            res[test] = "NO";
        }
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}

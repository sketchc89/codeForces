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
        /* Fence starts on the ground */
        int64_t lowestPossible = ground[0];
        int64_t highestPossible = ground[0];
        bool possible = true;

        /* for each new fence post the range of allowable starting heights expands by height of fence - 1
         * this is constraned on the bottom by the ground and the top by ground + height of fence - 1
         * first calculate the allowed range, then add the constraints */
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
        }
        /* Check that the ground of the last post is within the range of the second to last post */
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

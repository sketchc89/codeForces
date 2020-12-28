#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<int> res(tests);

    for (int test = 0; test < tests; ++test) {
        int numRed, numBlue;
        cin >> numRed;
        vector<int> red(numRed);
        for (int i = 0; i < red.size(); ++i) {
            cin >> red[i];
        }
        cin >> numBlue;
        vector<int> blue(numBlue);
        for (int i = 0; i < blue.size(); ++i) {
            cin >> blue[i];
        }
        res[test] = 0;
        int maxSumBlue = 0, sumBlue = 0;
        int maxSumRed = 0, sumRed = 0;
        for (int i = 0; i < blue.size(); ++i) {
            sumBlue += blue[i];
            maxSumBlue = max(maxSumBlue, sumBlue);
        }
        for (int i = 0; i < red.size(); ++i) {
            sumRed += red[i];
            maxSumRed = max(maxSumRed, sumRed);
        }
        // cout << '\n' << string(30, '-') << '\n' << "TEST: " << test << '\n' << string(30, '-') << '\n';
        // cout << "Blue: " << maxSumBlue << '\n';
        // cout << "Red: " << maxSumRed << '\n';
        res[test] = maxSumBlue + maxSumRed;
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}

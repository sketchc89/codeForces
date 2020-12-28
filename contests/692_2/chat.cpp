/*
ID: sketchc89
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o

    int tests;
    cin >> tests;

    vector<string> res(tests, "");
    for (int test = 0; test < tests; ++test) {
        int N;
        string s;
        cin >> N;
        cin >> s;
        for (auto it = crbegin(s); it != crend(s); ++it) {
            if (*it != ')') {
                // cout << distance(crbegin(s), it) << '\t' << distance(it, crend(s)) << '\n';
                if (distance(crbegin(s), it) > distance(it, crend(s))) {
                    res[test] = "Yes";
                } else {
                    res[test] = "No";
                }
                break;
            }
        }
        if (res[test] == "") {
            res[test] = "Yes";
        }
    }
    for (auto&& n : res) {
        cout << n << '\n';
    }


    return EXIT_SUCCESS;
}

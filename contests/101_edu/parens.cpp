#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<string> res(tests);

    for (int test = 0; test < tests; ++test) {
        string parens;
        cin >> parens;
        int N = parens.size();
        if (N % 2 == 1 || parens[0] == ')' || parens[N - 1] == '(') {
            res[test] = "NO";
        } else {
            res[test] = "YES";
        }
        // something tests
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}

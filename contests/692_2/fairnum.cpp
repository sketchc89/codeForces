/*
ID: sketchc89
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o

    int64_t tests;
    cin >> tests;

    vector<int64_t> res(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t num;
        cin >> num;
        array<bool, 10> s;
        for (auto n = num;; ++n) {
            auto temp = n;
            s.fill(false);
            while (temp) {
                if (temp % 10) {
                    s[temp % 10] = true;
                }
                temp /= 10;
            }
            bool valid = true;

            for (auto i = 2; i < s.size(); ++i) {
                if (s[i] && n % i != 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res[test] = n;
                break;
            }
        }
    }
    for (auto&& n : res) {
        cout << n << '\n';
    }


    return EXIT_SUCCESS;
}

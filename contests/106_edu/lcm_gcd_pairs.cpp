#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests, 0);
    string line = "\n" + string(30, '-') + "\n";
    for (int64_t test = 0; test < tests; ++test) {
        cout << line << "Test " << test << line;
        int c, d, x;
        cin >> c >> d >> x;
        for (int i = 1; i < 10000000; ++i) {
            for (int j = 1; j <= floor(sqrt(i)); ++j) {
                if (i % j == 0) {
                    int k = i / j;
                    // cout << i << ',' << j << " = " << c * i - d * j << '\n';
                    // cout << i << ',' << k << " = " << c * i - d * k << '\n';
                    if (c * i - d * j == x) {
                        cout << i << ',' << j << '\n';
                        if (i == j) {
                            cout << "Equal\n";
                            vi[test]++;
                        } else {
                            cout << "Not Equal\n";
                            vi[test] += 2;
                        }
                    } else if (c * i - d * k == x) {
                        cout << i << ',' << k << '\n';
                        if (i == k) {
                            cout << "Equal\n";
                            vi[test]++;
                        } else {
                            cout << "Not Equal\n";
                            vi[test] += 2;
                        }
                    }
                }
            }
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

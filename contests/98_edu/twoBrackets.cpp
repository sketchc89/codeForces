#include <bits/stdc++.h>

using namespace std;

int64_t twoBrackets(const string& s) {
    int64_t score = 0, sq = 0, round = 0, curl = 0;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case '[':
                ++sq;
                break;
            case '{':
                ++curl;
                break;
            case '(':
                ++round;
                break;
            case ']':
                if (sq) {
                    --sq;
                    ++score;
                }
                break;
            case ')':
                if (round) {
                    --round;
                    ++score;
                }
                break;
            case '}':
                if (curl) {
                    --curl;
                    ++score;
                }
                break;
            default:
                cerr << "ERROR\n";
                break;
        }
    }
    return score;
}

int main() {
    int64_t tests;
    cin >> tests;
    cin.ignore(numeric_limits<int>::max(), '\n');
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        string parens = "";
        getline(cin, parens);
        vi[test] = twoBrackets(parens);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

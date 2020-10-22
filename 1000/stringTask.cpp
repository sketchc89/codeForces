#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; }),
            s.end());
    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        res.push_back('.');
        res.push_back(s[i]);
    }
    cout << res;
    return 0;
}

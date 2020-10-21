#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;

  string AB("AB"), BA("BA");
  getline(cin, s);
  int minAB = numeric_limits<int>::max(), maxAB = numeric_limits<int>::min();
  int minBA = numeric_limits<int>::max(), maxBA = numeric_limits<int>::min();
  int pos = 0;

  while (pos != string::npos) {
    pos = s.find("AB", pos);
    if (pos != string::npos) {
      minAB = min(minAB, pos);
      maxAB = max(maxAB, pos);
      pos += 2;
    }
  }
  pos = 0;
  while (pos != string::npos) {
    pos = s.find("BA", pos);
    if (pos != string::npos) {
      minBA = min(minBA, pos);
      maxBA = max(maxBA, pos);
      pos += 2;
    }
  }
  if (maxAB == numeric_limits<int>::min() ||
      maxBA == numeric_limits<int>::min()) {
    cout << "NO";
  } else if (abs(maxAB - maxBA) > 1 || abs(minAB - minBA) > 1 ||
             abs(maxAB - minBA) > 1 || abs(minAB - maxBA) > 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}

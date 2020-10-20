#include <iostream>
#include <sstream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::ostringstream oss;
  std::string s;
  for (int i = 0; i <= n; ++i) {
    std::getline(std::cin, s);
    if (s.size() > 10) {
      s = s[0] + std::to_string(s.size() - 2) + s[s.size() - 1];
    }
    oss << s << '\n';
  }
  std::cout << oss.str();
  return 0;
}

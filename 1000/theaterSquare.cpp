#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
    double l, w, a;
    std::cin >> l >> w >> a;
    int64_t res = std::ceil(l / a) * std::ceil(w / a);
    std::cout << res;
    return 0;
}

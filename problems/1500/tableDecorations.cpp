/* Failing */

#include <bits/stdc++.h>

using namespace std;

enum class Color {
    None,
    Red,
    Blue,
    Green,
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t r, g, b;
    cin >> r >> g >> b;

    int64_t tableCount = 0;
    int64_t maxBaloon = numeric_limits<int64_t>::min();
    int64_t minBaloon = numeric_limits<int64_t>::max();
    while (r + g + b >= 3) {
        auto firstSpot = Color::None;
        auto secondSpot = Color::None;
        maxBaloon = max(r, max(g, b));
        minBaloon = min(r, min(g, b));
        if (maxBaloon - minBaloon <= 1) {  // exit early when baloons are close to one another
            tableCount += (r + g + b) / 3;
            break;
        }
        if (r + g + b - maxBaloon < maxBaloon / 2) {  // reduce unpairable baloons
            if (r > g && r > b) {
                r /= 2;
            } else if (g > b && g > r) {
                g /= 2;
            } else {
                b /= 2;
            }
        }

        if (r > g && r > b) {
            --r;
            firstSpot = Color::Red;
        } else if (g > r && g > b) {
            --g;
            firstSpot = Color::Green;
        } else if (b > 0) {
            --b;
            firstSpot = Color::Blue;
        } else {
            --r;
            firstSpot = Color::Red;
        }

        // check second spot
        if (r > g && r > b) {
            --r;
            secondSpot = Color::Red;
        } else if (g > r && g > b) {
            --g;
            secondSpot = Color::Green;
        } else if (b > 0) {
            --b;
            secondSpot = Color::Blue;
        } else {
            if (g > 0 && firstSpot == Color::Red) {
                --g;
                secondSpot = Color::Green;
            } else if (r > 0) {
                --r;
                secondSpot = Color::Red;
            } else {
                break;
            }
        }
        if (r > g && r > b) {
            if (firstSpot == secondSpot && firstSpot == Color::Red) {
                if (g > b && g > 0) {
                    --g;
                    ++tableCount;
                } else if (b > 0) {
                    --b;
                    ++tableCount;
                } else {
                    break;
                }

            } else if (r > 0) {
                --r;
                ++tableCount;
            }
        } else if (g > r && g > b) {
            if (firstSpot == secondSpot && firstSpot == Color::Green) {
                if (r > b && r > 0) {
                    --r;
                    ++tableCount;
                } else if (b > 0) {
                    --b;
                    ++tableCount;
                } else {
                    break;
                }
            } else if (g > 0) {
                --g;
                ++tableCount;
            }
        } else if (b > r && b > g) {
            if (firstSpot == secondSpot && firstSpot == Color::Blue) {
                if (r > g && r > 0) {
                    --r;
                    ++tableCount;
                } else if (g > 0) {
                    --g;
                    ++tableCount;
                } else {
                    break;
                }
            } else if (b > 0) {
                --b;
                ++tableCount;
            }
        } else {
            if (r > 0 && firstSpot != Color::Red) {
                --r;
                ++tableCount;
            } else if (g > 0 && firstSpot != Color::Green) {
                --g;
                ++tableCount;
            } else if (b > 0 && firstSpot != Color::Blue) {
                --b;
                ++tableCount;
            } else {
                break;
            }
        }
    }
    cout << tableCount;

    return 0;
}

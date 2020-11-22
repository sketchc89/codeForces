/* Failing */

#include <bits/stdc++.h>

using namespace std;

void sieve(array<bool, 10000001>& arr) {
    arr[1] = false;
    for (int64_t i = 2; i < arr.size(); ++i) {
        for (int64_t j = i * i; j < arr.size(); j += i) {
            arr[j] = false;
        }
    }
}

int64_t division(int64_t p, int64_t q, const array<bool, 10000001>& arr) {
    if (p % q != 0) {
        return p;
    }
    set<int64_t, greater<int>> nums;
    for (int64_t i = 2; i <= sqrt(q); ++i) {
        int64_t newP = p;
        while (arr[i] && newP % i == 0) {
            // cout << newP << '%' << i << '=' << newP % i << " next ";
            newP /= i;
            // cout << newP << '\t';
            nums.insert(newP);
        }
    }
    // cout << '\n';
    for (int num : nums) {
        // cout << num << '\n';
        if (num % q != 0) {
            return num;
        }
    }
    return 1;
}

int main() {
    array<bool, 10000001> arr;
    arr.fill(true);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(arr);
    int N = 0;
    int64_t p, q;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p >> q;
        cout << division(p, q, arr) << '\n';
    }
    return 0;
}

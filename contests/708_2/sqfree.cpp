#include <bits/stdc++.h>

using namespace std;


int primeComplement(int num) {
    int res = 1;
    vector<int> sieveArr(num + 1, 1);
    sieveArr[0] = false;
    sieveArr[1] = false;
    int limit = num;
    for (int64_t i = 2; i <= limit; ++i) {
        if (sieveArr[i]) {
            int cnt = 0;
            while (num % i == 0) {
                ++cnt;
                num /= i;
            }
            if (cnt % 2 == 1) {
                res *= i;
            }
            for (int64_t j = i * i; j < sieveArr.size(); j += i) {
                sieveArr[j] = false;
            }
        }
    }
    return res;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    unordered_set<int> complements, vals;
    for (int64_t test = 0; test < tests; ++test) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        complements.clear();
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            auto complement = primeComplement(nums[i]);
            // cout << nums[i] << '\t' << complement << '\n';
            if (complements.count(complement)) {
                complements.clear();
                vi[test]++;
                // cout << "Found match at " << i << '\n';
            }
            complements.insert(complement);
        }
        if (complements.size() != 0) {
            vi[test]++;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}

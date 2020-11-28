/* IN PROGRESS
 * TODO
 * */
#include <bits/stdc++.h>

using namespace std;

struct Segment {
    Segment(int s, int e)
            : start{s}
            , end{e} {}
    int start, end;
};

bool operator<(const Segment& lhs, const Segment& rhs) {
    int lmid = lhs.start + (lhs.end - lhs.start) / 2;
    int rmid = rhs.start + (rhs.end - rhs.start) / 2;
    if (lmid != rmid) {
        return lmid < rmid;
    }
    return lhs.start < rhs.start;
}

int64_t editorials(const int segLen, const int numProblems, vector<Segment>& segments) {
    array<int64_t, 2000> problems;
    problems.fill(0);
    sort(segments.begin(), segments.end());
    for (auto&& seg : segments) {
        cout << seg.start << '-' << seg.end << '\t';
        for (int i = seg.start; i <= seg.end; ++i) {
            problems[i]++;
        }
    }
    cout << '\n';
    int64_t sum = 0;

    for (int i = 0; i < numProblems - segLen; ++i) {
        sum = 0;
        for (int j = i; j < i + segLen; ++j) {
            sum += problems[j];
        }
        cout << i << ':' << sum /*problems[i] */ << '\t';
    }
    return 0;
}

int main() {
    int64_t problems, participants, segLen;

    cin >> problems >> participants >> segLen;
    vector<Segment> inp;
    for (int64_t p = 0; p < participants; ++p) {
        int s, e;
        cin >> s >> e;
        inp.emplace_back(Segment(s - 1, e - 1));
    }
    cout << editorials(segLen, problems, inp) << '\n';
    return 0;
}

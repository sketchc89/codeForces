/*
ID: sketchc1
LANG: C++14
TASK: milk
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o
    int tests;
    cin >> tests;
    vector<int64_t> res(tests);
    for (int test = 0; test < tests; ++test) {
        int numCommands;
        cin >> numCommands;
        vector<pair<int64_t, int64_t>> commands(numCommands);
        for (int c = 0; c < commands.size(); ++c) {
            cin >> commands[c].first >> commands[c].second;
        }
        // at time t = 0,
        // start moving state, move forward in time, keep track of target position
        // for the first command, the position won't be reached until pos + t
        // for the second command, during start moving state, set the currPos to t2 - t1 and it is successful if if the pos is less
        int64_t currPos = 0;
        int64_t timeEnd = 0;
        int64_t targetPos = 0;
        res[test] = 0;
        // cout << "\nTest: " << test << "\n" << string(100, '-') << "\n";
        for (int i = 0; i < commands.size(); ++i) {

            // If the current time is more than the previous time end, then set the currPosition to the previous target position and new
            // time end to
            // be the current time commands[i].first + the distance to the new target.
            // Otherwise update the current position to be the time difference since the last command in the direction of the target
            // position
            int64_t currTarget = commands[i].second;
            int64_t timeCurrCommand = commands[i].first;
            int64_t timeNextCommand = i == commands.size() - 1 ? INT64_MAX : commands[i + 1].first;
            if (timeCurrCommand >= timeEnd) {
                // cout << "Stopped\t";
                currPos = targetPos;
                targetPos = currTarget;
                timeEnd = timeCurrCommand + abs(targetPos - currPos);
                // if (targetPos > currPos) {
                //     cout << " forward\t";
                // } else if (targetPos < currPos) {
                //     cout << " backward\t";
                // } else {
                //     cout << " in place\t";
                // }
            } else {
                // cout << "Moving\t";

                if (targetPos > currPos) {
                    // cout << " forward\t";
                    currPos += timeCurrCommand - commands[i - 1].first;
                } else if (targetPos < currPos) {
                    // cout << " backward\t";
                    currPos -= timeCurrCommand - commands[i - 1].first;
                } else {
                    // cout << " in place\t";
                }
            }

            // cout << "Time: " << setw(9) << timeCurrCommand << "\tPosition: " << setw(9) << currPos << "\t";
            // cout << "Robot target:   " << setw(9) << targetPos << "\t";
            // cout << "Command target: " << setw(9) << currTarget << "\t";

            // if the target and the current position match then the command is successful
            if (targetPos - currPos == 0) {
                res[test]++;
                // cout << "Success: robot target is " << targetPos << " and is already there\n";

                // if the robot is moving forward and the current commands target is backward then fail
            } else if (targetPos - currPos > 0) {
                if (currTarget - currPos < 0) {
                    // cout << "Failure: robot target is " << targetPos << " but command desires " << currTarget << '\n';
                } else if (currTarget > targetPos) {
                    // cout << "Failure: robot target is " << targetPos << " but command target " << currTarget
                    //      << " is more forward than that\n";
                } else if (timeNextCommand - timeCurrCommand < currTarget - currPos) {
                    // cout << "Failure: command target is " << currTarget << " but command cannot reach there from " << currPos << " in "
                    //      << timeNextCommand - timeCurrCommand << " seconds\n";
                } else {
                    res[test]++;
                    // cout << "Success: command target is " << currTarget << " and will reach there from " << currPos << " in "
                    //      << timeNextCommand - timeCurrCommand << " seconds\n";
                }
            } else if (targetPos - currPos < 0) {
                if (currTarget - currPos > 0) {
                    // cout << "Failure: robot target is " << targetPos << " but command desires " << currTarget << '\n';
                } else if (currTarget < targetPos) {
                    // cout << "Failure: robot target is " << targetPos << " but command " << currTarget << " is more backward than that\n";
                } else if (timeNextCommand - timeCurrCommand < currPos - currTarget) {
                    // cout << "Failure: command target is " << currTarget << " but command cannot reach there from  " << currPos << " in "
                    //      << timeNextCommand - timeCurrCommand << " seconds\n";
                } else {
                    res[test]++;
                    // cout << "Success: command target is " << currTarget << " and will reach there from " << currPos << " in "
                    //      << timeNextCommand - timeCurrCommand << " seconds\n";
                }
            } else {
                // cout << "FATAL impoosible\n";
                abort();
            }
        }
        // if (commands[commands.size() - 1].first >= timeEnd || (targetPos - currPos > 0 && commands[commands.size() - 1].second >
        // currPos
        //                                                        && commands[commands.size() - 1].second <= targetPos)
        //     || (targetPos - currPos < 0 && commands[commands.size() - 1].second < currPos
        //         && commands[commands.size() - 1].second >= targetPos)) {
        //     // cout << "Last command success\n";
        //     res[test]++;
        // } else {
        //     // cout << "Last command ignored\n";
        // }
    }
    for (auto test : res) {
        cout << test << '\n';
    }


    return EXIT_SUCCESS;
}

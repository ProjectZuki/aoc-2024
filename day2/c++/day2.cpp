/**
 * @file day2.cpp
 * @author ProjectZuki
 * @brief AOC 2024 Day 2 Part 1: Determines safety levels based on defined constraints.
 *          - The levels are either all increasing or all decreasing.
 *          - Any two adjacent levels differ by at least one and at most three.
 * @date 2024-12-02
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int safe = 0;
    int unsafe = 0;
    int num;
    // safe if either all increasing or all decreasing
    // safe if any two adjacent levels differ by at least 1 and at most 3

    while (!cin.eof()) {
        vector<int> level;
        while (cin.peek() != '\n' && cin >> num) {
            level.push_back(num);
        }
        cin.ignore();

        // for (int i = 0; i < level.size(); i++) {
        //     cout << level.at(i) << " ";
        // }
        // cout << endl;

        bool isSafe = true;
        bool dec = false;
        bool inc = false;

        for (size_t i = 1; i < level.size() && isSafe; i++) {

            if (level.at(i) > level.at(i-1)) {
                inc = true;
            } else if (level.at(i) < level.at(i-1)) {
                dec = true;
            } else {
                isSafe = false;
                // cout << "one value not increasing or decreasing" << endl;
                break;
            }

            auto diff = abs(level.at(i) - level.at(i-1));
            if (diff > 3 || diff < 1) {
                isSafe = false;
                // cout << "exceeds threshold" << endl;
                
            }

            if (dec && inc) {
                isSafe = false;
                // cout << "increasing and decreasing" << endl;
                break;
            } 
        }

        if (isSafe) {
            safe++;
            // cout << "safe" << endl;
        } else {
            unsafe++;
            // cout << "unsafe" << endl;
        }
        // cout << endl;
    }

    cout << "# safe levels: " << safe << endl;
    cout << "# unsafe levels: " << unsafe << endl;

    return 0;
}
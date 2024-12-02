/**
 * @file day1.cpp
 * @author ProjectZuki
 * @brief AOC 2024 Day 1 Part 1: reads pairs of integers from standard input and stores 
         them into two separate lists. It then sorts both lists, compares their 
         corresponding elements, and computes the total difference between 
         mismatched elements across the lists.
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Main entry point for the program. Inputs until end of file (command line)
 *          and processes each input to check the total difference between each
 *          incremental value of the input columns after sorting
 * 
 * @return 0 if success
 */
int main() {

    int val1;           // first value
    int val2;           // second value
    int total = 0;      // total difference
    vector<int> row1;   // first row of values
    vector<int> row2;   // second row of values
    
    // Input both columns of values
    while (!cin.eof()) {
        cin >> val1 >> val2;
        row1.push_back(val1);
        row2.push_back(val2);
    }

    // sort, check difference of each identical index to sum the total
    sort(row1.begin(), row1.end());
    sort(row2.begin(), row2.end());

    for (int i = 0; i < row1.size(); i++) {
        if (row1[i] != row2[i]) {
            total+= abs(row1[i] - row2[i]);
        }
    }

    cout << "Total: " << total << endl;

    return 0;
}

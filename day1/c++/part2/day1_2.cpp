/**
 * @file day1_2.cpp
 * @author ProjectZuki
 * @brief AOC Day 1 Part 2: Checks the number of occurences which each value of
 *          the left column appears in the right, and outputs the total similarities.
 * @date 2024-12-01
 */

#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Main entry point for the program. Input from the command line until EOF.
 *          Left column is stored in Vector, right column into hash table to check occurences.
 * 
 * @return 0 if success
 */
int main() {

    int val1, val2;                 // values to be processed
    int simlarityscore = 0;         // keep track of similarities
    unordered_map <int, int> map;   // hash table to check occurences of right col
    vector<int> row1;               // vector to store values in left column
    
    // input variables into vector and hash table
    while (!cin.eof()) {
        cin >> val1 >> val2;
        row1.push_back(val1);
        map[val2]++;
    }

    // check occurences of all left column values on right column
    for (int i = 0; i < row1.size(); i++) {
        if (map.find(row1[i]) != map.end()) {
            simlarityscore += row1[i] * map[row1[i]];
        }
    }

    cout << "similarity score: " << simlarityscore << endl;

    return 0;
}

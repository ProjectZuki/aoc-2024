/**
 * @file day2_2.cpp
 * @author ProjectZuki
 * @brief AOC 2024 Day 2 Part 2: Determines safety levels based on defined constraints.
 *          Removing one element at at time if unsafe, to check if still safe.
 * @date 2024-12-02
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

istream& operator>>(istream& is, vector<int>& vec);
bool checkSafe(vector<int> level);
int checkRemoval(vector<int> vec);

/**
 * @brief Main entry point for the program. Reads each level of input, checking
 *          if they are safe. If not safe, check to see if a single element
 *          can be removed to make it safe.
 * 
 * @return EXIT_SUCCESS if success
 */
int main() {

    int safe = 0;

    vector<int> level;
    while (cin >> level) {
        safe += checkSafe(level)? 1 : checkRemoval(level);
    }

    cout << "# safe levels: " << safe << endl;

    return EXIT_SUCCESS;
}

/**
 * @brief Overload ('>>') to read one line of whitespace-separated
 *          integers into the vector
 * 
 * @param is input stream
 * @param vec vector to store values
 * @return istream&  Ref to input stream
 */
istream& operator>>(istream& is, vector<int>& vec) {
    vec.clear();
    int num;

    while (is.peek() != '\n' && is.peek() != EOF && is >> num) {
        vec.push_back(num);
    }
    is.ignore();
    
    return is;
}

/**
 * @brief checks if the current level is safe based on conditions:
 *              - Sequence must increase OR decrease
 *              - Difference must be between 1 - 3
 * 
 * @param level vector of report values
 * @return true if safe, else false
 */
bool checkSafe(vector<int> level) {
    bool dec = false;
    bool inc = false;

    for (size_t i = 1; i < level.size(); i++) {

        // check if incrementing or decrementing, unsafe if neither
        if (level.at(i) > level.at(i-1)) {
            inc = true;
        } else if (level.at(i) < level.at(i-1)) {
            dec = true;
        } else {
            return false;
        }

        // check threshold of inc/dec
        auto diff = abs(level.at(i) - level.at(i-1));
        if (diff > 3 || diff < 1) {
            return false;
        }

        // unsafe if incrementing and decrementing
        if (dec && inc) {
            return false;
        } 
    }

    return true;
}


/**
 * @brief Removes a single element at a time and checks if the level is still valid.
 * 
 * @param vec vector of integers representing the report level
 * @return 1 if safe, else 0
 */
int checkRemoval(vector<int> vec) {

    int safe = 0;               // 1 if safe, else 0
    vector<int> temp = vec;     // temp vector to erase elements with

    for (size_t idx = 0; idx < vec.size(); idx++) {
        // reset the vector, erase next value
        temp = vec;
        temp.erase(temp.begin() + idx);

        // check if safe
        if (checkSafe(temp)){
            safe++;
            break;
        }
    }
    return safe;
}

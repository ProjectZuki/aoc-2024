/**
 * @file day2.cpp
 * @author ProjectZuki
 * @brief AOC 2024 Day 3 Part 1: 
 * @date 2024-12-03
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int processMul(string line);
int checkvalid(string line);
unsigned int mul(string num1, string num2);

/**
 * @brief Main entry point for the program. Parses input to check for strings matching
 *          "mul(X,Y)" where X, Y are integers, and multiply X*Y. The program will find all
 *          instances and add up all of the results of the multiplications.
 * 
 * @return EXIT_SUCCESS if success
 * @note https://adventofcode.com/2024/day/3
 */
int main() {

    string line;
    unsigned int total = 0;

    while(getline(cin, line)) {

        total += processMul(line);

    }

    cout << "Total: " << total << endl;

    return EXIT_SUCCESS;
}

/**
 * @brief Processes the multiplications of the string under the condition that it finds
 *          the string "mul(X,Y)" where X and Y are integers
 * 
 * @param line the string to be parsed
 * @return int the total for this sequence
 */
int processMul(string line) {
    int total = 0;
    size_t index = line.find("mul(");
    while (index != string::npos) {

        // cout << "Line: " << line << endl;
        // cout << "found mul at index: " << index << "\n";

        string temp = line.substr(index+4);
        int mul = checkvalid(temp);
        if (mul != -1) {
            // cout << "Valid!" << endl;
            total += mul;
        } else {
            // cout << "Invalid!" << endl;
        }

        line = line.substr(index+1, line.length());
        // cout << "New Line: " << line << "\n\n";
        index = line.find("mul(");
    }

    return total;
}

/**
 * @brief Checks if the instance of mul(x,y) is valid, where x and y must be integers
 *           and the format must be in the form "mul(x,y)" else return -1 for invalid
 * 
 * @param line string to be parsed after "mul("
 * @return int -1 if invalid, otherwise the product of the two numbers
 */
int checkvalid(string line) {

    // At this point, we know "mul(" is found, we expect "X,Y)"
    // cout << line << endl;

    unsigned int pos = 0;   // tracks position of string
    string num1 = "";       // first number if found
    string num2 = "";       // second number if found

    char ch = line[pos];    

    // parse first number
    while (isdigit(ch)) {
        
        num1 += ch;
        ch = line[++pos];
    }

    // parse next digit after ',' else return invalid -1
    if (ch == ',') {
        pos++;
        ch = line[pos];
        
        // parse second number
        while (isdigit(ch)) {
            num2 += ch;
            ch = line[++pos];
        }
        if (ch != ')') {
            return -1;
        }
    } else {
        return -1;
    }

    // cout << "num1: " << num1 << "\tnum2: " << num2 << endl;

    return mul(num1, num2);
}

/**
 * @brief Multiplies num1 and num2 after converting from a string
 * 
 * @param num1 first number as a string
 * @param num2 second number as a string
 * @return unsigned int the product of num1 and num2
 */
unsigned int mul(string num1, string num2) {
    return stoi(num1) * stoi(num2);
}

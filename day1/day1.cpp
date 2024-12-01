#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int val1;
    int val2;
    int total = 0;
    vector<int> row1;
    vector<int> row2;
    

    while (!cin.eof()) {
        cin >> val1 >> val2;
        row1.push_back(val1);
        row2.push_back(val2);
    }

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
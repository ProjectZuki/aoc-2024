#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    int val1, val2;
    int simlarityscore = 0;
    unordered_map <int, int> map;
    vector<int> row1;
    vector<int> row2;
    

    while (!cin.eof()) {
        cin >> val1 >> val2;
        row1.push_back(val1);
        map[val2]++;
    }

    for (int i = 0; i < row1.size(); i++) {
        if (map.find(row1[i]) != map.end()) {
            simlarityscore += row1[i] * map[row1[i]];
        }
    }

    cout << "similarity score: " << simlarityscore << endl;

    return 0;
}
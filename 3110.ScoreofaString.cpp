#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            total += abs(s[i] - s[i + 1]);
        }
        return total;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string test1 = "abc";
    cout << "Score of string \"" << test1 << "\": " << solution.scoreOfString(test1) << endl;

    // Test case 2
    string test2 = "abcd";
    cout << "Score of string \"" << test2 << "\": " << solution.scoreOfString(test2) << endl;

    // Test case 3
    string test3 = "a";
    cout << "Score of string \"" << test3 << "\": " << solution.scoreOfString(test3) << endl;

    // Test case 4
    string test4 = "zxy";
    cout << "Score of string \"" << test4 << "\": " << solution.scoreOfString(test4) << endl;

    // Test case 5
    string test5 = "abz";
    cout << "Score of string \"" << test5 << "\": " << solution.scoreOfString(test5) << endl;

    return 0;
}

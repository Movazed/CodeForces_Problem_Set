#include <iostream>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;
        int s_length = s.length(), t_length = t.length();

        while (s_index < s_length && t_index < t_length) {
            if (s[s_index] == t[t_index]) {
                t_index++;
            }
            s_index++;
        }

        return t_length - t_index;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "abc";
    string t1 = "abcd";
    cout << "Result for s1 and t1: " << solution.appendCharacters(s1, t1) << endl;

    string s2 = "xyz";
    string t2 = "xyabcz";
    cout << "Result for s2 and t2: " << solution.appendCharacters(s2, t2) << endl;

    return 0;
}

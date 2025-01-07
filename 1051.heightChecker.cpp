#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int n=heights.size(), ans=0;
        for(int i=0; i<n;i++)
            ans += (heights[i]!=sorted[i]);
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {
    Solution sol;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << "Number of students who have heights not in the correct order: " << sol.heightChecker(heights) << endl;
    return 0;
}

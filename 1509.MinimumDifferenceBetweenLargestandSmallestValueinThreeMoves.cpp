#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int ans = nums[n-1] - nums[0];
        
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, nums[n-(4-i)] - nums[i]);
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 0, 10, 14};
    cout << solution.minDifference(nums) << endl; // Output: 1
    return 0;
}

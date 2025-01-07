#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> position;
    int m;

    // Example test case 1
    position = {1, 2, 3, 4, 7};
    m = 3;
    cout << "Maximum distance: " << solution.maxDistance(position, m) << endl;

    // Example test case 2
    position = {5, 4, 3, 2, 1, 1000000000};
    m = 2;
    cout << "Maximum distance: " << solution.maxDistance(position, m) << endl;

    // Add more test cases as needed
    position = {1, 2, 8, 4, 9};
    m = 3;
    cout << "Maximum distance: " << solution.maxDistance(position, m) << endl;

    return 0;
}

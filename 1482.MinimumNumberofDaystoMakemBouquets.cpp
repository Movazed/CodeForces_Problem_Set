#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "Minimum number of days for test case 1: " << solution.minDays(bloomDay1, m1, k1) << endl; // Expected output: 3

    // Test case 2
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "Minimum number of days for test case 2: " << solution.minDays(bloomDay2, m2, k2) << endl; // Expected output: -1

    // Test case 3
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    cout << "Minimum number of days for test case 3: " << solution.minDays(bloomDay3, m3, k3) << endl; // Expected output: 12

    // Test case 4
    vector<int> bloomDay4 = {1000000000, 1000000000};
    int m4 = 1, k4 = 1;
    cout << "Minimum number of days for test case 4: " << solution.minDays(bloomDay4, m4, k4) << endl; // Expected output: 1000000000

    return 0;
}

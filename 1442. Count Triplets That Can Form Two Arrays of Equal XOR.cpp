#include <iostream>
#include <vector>

//The function Solution is the answer rest are to complete this code
class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] ^ arr[i - 1];
        int total = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    if (pref[j - 1] ^ pref[i - 1] == pref[k] ^ pref[j - 1])
                        total++;
                }
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {2, 3, 1, 6, 7};
    std::cout << "Number of triplets: " << sol.countTriplets(arr) << std::endl;
    return 0;
}

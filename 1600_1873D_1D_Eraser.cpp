#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t); // Read the number of test cases

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k); // Read n and k

        int ans = 0;
        char s[n + 1]; // +1 to leave space for null terminator
        scanf("%s", s); // Read the string

        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                ans++;       // Count this 'B'
                i += k - 1;  // Skip the next k - 1 positions
            }
        }

        printf("%d ", ans); // Output the answer for this test case
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>

int squirrelFood(int input1, int input2, int input3[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = input1;
    int K = input2;

    vector<ll> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = input3[i];
    }
    sort(p.begin(), p.end());

    vvi cost(N, vi(N, 0));
    vi prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int m_idx = i + (j - i) / 2;
            ll median = p[m_idx];

            ll left_count = m_idx - i + 1;
            ll left_pos_sum = prefix_sum[m_idx + 1] - prefix_sum[i];
            ll left_dist = left_count * median - left_pos_sum;

            ll right_count = j - m_idx;
            ll right_pos_sum = prefix_sum[j + 1] - prefix_sum[m_idx + 1];
            ll right_dist = right_pos_sum - right_count * median;
            
            cost[i][j] = left_dist + right_dist;
        }
    }

    const ll INF = 1e18;
    vvi dp(K + 1, vi(N + 1, INF));
    
    dp[0][0] = 0;

    for (int k = 1; k <= K; ++k) {
        for (int n = 1; n <= N; ++n) {
            for (int prev_n = 0; prev_n < n; ++prev_n) {
                if (dp[k - 1][prev_n] != INF) {
                    dp[k][n] = min(dp[k][n], dp[k - 1][prev_n] + cost[prev_n][n - 1]);
                }
            }
        }
    }

    return (int)dp[K][N];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    
    cout << "Enter the number of squirrels (N) and food packets (K): ";
    cin >> N >> K;


    int positions[N];

    cout << "Enter the " << N << " squirrel positions: ";
    for (int i = 0; i < N; ++i) {
        cin >> positions[i];
    }

    int result = squirrelFood(N, K, positions);

    cout << "\nMinimum total distance: " << result << endl;

    return 0;
}
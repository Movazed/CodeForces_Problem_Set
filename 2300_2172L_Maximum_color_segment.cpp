#include <bits/stdc++.h>
using namespace std;


vector<int> solve_chain(const vector<int>& chain) {
    int n = chain.size();

    int max_ops = n + 1; 
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(max_ops + 1, vector<int>(2, -1e9)));

    dp[0][0][0] = 0;
    

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= max_ops; ++j) {

            if (dp[i][j][0] > -1e9) {
                int current_val = chain[i]; // Unchanged
                
                // Option A: Don't start a flip at i
                // i contributes current_val. Next state receives 0 flip.
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0] + current_val);
                
                // Option B: Start a flip at i (affects i and i+1)
                // i becomes !current_val. Next state receives 1 flip. Cost +1.
                if (j + 1 <= max_ops) {
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][0] + (1 - current_val));
                }
            }
            
            // Case 1: We received a flip from i-1
            if (dp[i][j][1] > -1e9) {
                int current_val = 1 - chain[i]; // Flipped by incoming
                
                // Option A: Don't start a flip at i
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][1] + current_val);
                
                // Option B: Start a flip at i
                if (j + 1 <= max_ops) {
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][1] + (1 - current_val));
                }
            }
        }
    }
    
    // The final result for this chain is max of dp[n][j][0]. 
    // dp[n][j][1] is invalid because we can't start an operation at the very end extending beyond.
    vector<int> res;
    for(int j=0; j<=max_ops; ++j) {
        if(dp[n][j][0] > -1e9) res.push_back(dp[n][j][0]);
    }
    return res;
}

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;
    string s;
    cin >> s;


    vector<int> D(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        D[i] = (s[i] != s[i+1] ? 1 : 0);
    }


    vector<int> dp_global(m + 1, -1e9);
    dp_global[0] = 0;

    vector<bool> visited(n + 1, false);

    for (int r = 0; r < k; ++r) {
        
        vector<int> chain_vals;

        
        for (int idx = r; idx <= n; idx += k) {
            if (idx == 0 || idx == n) {

                chain_vals.push_back((idx > 0 && idx < n) ? D[idx-1] : 0);
            } else {
                chain_vals.push_back(D[idx-1]);
            }
        }
        
        if (chain_vals.empty()) continue;

        int len = chain_vals.size();

        vector<bool> is_real;
        for (int idx = r; idx <= n; idx += k) {
            is_real.push_back(idx > 0 && idx < n);
        }

        int max_ops_chain = len + 2; 

        vector<vector<vector<int>>> chain_dp(len + 1, vector<vector<int>>(max_ops_chain, vector<int>(2, -1e9)));
        
        chain_dp[0][0][0] = 0;
        
        for (int i = 0; i < len; ++i) {
            for (int ops = 0; ops < max_ops_chain; ++ops) {
  
                if (chain_dp[i][ops][0] > -1e9) {
                    int val = chain_vals[i]; 
                    int score_contrib = is_real[i] ? val : 0;
                    
                    // Don't start op
                    chain_dp[i+1][ops][0] = max(chain_dp[i+1][ops][0], chain_dp[i][ops][0] + score_contrib);
                    
                    // Start op (connects i and i+1)
                    // If we start op, i is flipped. i+1 will be flipped.
                    int flipped_val = 1 - val;
                    int flipped_score = is_real[i] ? flipped_val : 0;
                    if (ops + 1 < max_ops_chain) {
                        chain_dp[i+1][ops+1][1] = max(chain_dp[i+1][ops+1][1], chain_dp[i][ops][0] + flipped_score);
                    }
                }
                
                // State 1: Flipped by previous
                if (chain_dp[i][ops][1] > -1e9) {
                    int val = 1 - chain_vals[i]; // currently flipped
                    int score_contrib = is_real[i] ? val : 0;
                    
                    // Don't start op
                    chain_dp[i+1][ops][0] = max(chain_dp[i+1][ops][0], chain_dp[i][ops][1] + score_contrib);
                    
                    // Start op
                    int flipped_back = 1 - val;
                    int flipped_back_score = is_real[i] ? flipped_back : 0;
                     if (ops + 1 < max_ops_chain) {
                        chain_dp[i+1][ops+1][1] = max(chain_dp[i+1][ops+1][1], chain_dp[i][ops][1] + flipped_back_score);
                    }
                }
            }
        }
        
        // Extract costs for this chain
        // We only care about chain_dp[len][ops][0] because we can't have an open operation at the end
        vector<int> costs;
        for(int ops=0; ops < max_ops_chain; ++ops) {
            if (chain_dp[len][ops][0] > -1e9) {
                // We create a sparse pair or just vector logic
                // Since we need to merge, let's keep it index based.
                // However, M is up to 3000. Merging naively is O(M^2) per chain. 
                // Total operations across all chains <= M.
                // Actually, sum of lengths of chains is roughly N.
                // The knapsack merge is basically adding vector sizes. O(N*M).
                // costs[c] = max gain
                costs.push_back(chain_dp[len][ops][0]);
            } else {
                costs.push_back(-1e9);
            }
        }
        
        // Merge into global
        vector<int> next_dp(m + 1, -1e9);
        // Optimization: track max ops used so far in global to reduce inner loop range
        for (int w = 0; w <= m; ++w) {
            if (dp_global[w] == -1e9) continue;
            for (int c = 0; c < costs.size(); ++c) {
                if (w + c > m) break;
                if (costs[c] > -1e9) {
                    next_dp[w + c] = max(next_dp[w + c], dp_global[w] + costs[c]);
                }
            }
        }
        dp_global = next_dp;
    }

    // Answer is max in dp_global + 1 (for the first segment)
    int ans = 0;
    for (int x : dp_global) ans = max(ans, x);
    cout << ans + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
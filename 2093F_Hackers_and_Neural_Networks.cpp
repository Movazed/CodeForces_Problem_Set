#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define fast_io ios::base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<vector<string>> b(m, vector<string>(n));
    vector<int> match_masks;

    for(int i = 0; i < m; ++i){
        int current_mask = 0;
        for(int j = 0; j < n; ++j){
            cin >> b[i][j];
            if(b[i][j] == a[j]){
                current_mask |= (1 << j);
            }
        }
        match_masks.push_back(current_mask);
        
    }

    vector<bool> is_coverable(1 << n, false);
    for(int mask : match_masks){
        is_coverable[mask] = true;
    }

    for(int i = 0; i < n; ++i){
        for(int mask = (1 << n) - 1;  mask >= 0; --mask){
            if(mask & (1 << i)){
                is_coverable[mask ^(1 << i)] = is_coverable[mask ^ (1 << i)] || is_coverable[mask];
            }
        }
    }

    vector<int> dp(1 << n, -1);

    function<int(int)> compute_dp = [&](int mask) -> int {
        if(mask == 0){
            return 0;
        }
        if(dp[mask] != -1){
            return dp[mask];
        }
        if(!is_coverable[mask]){
            return dp[mask] = INF;
        }
        int max_prev_dp = 0;

        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                max_prev_dp = max(max_prev_dp, compute_dp(mask ^ (1 << i)));
            }
        }
        if(max_prev_dp >= INF){
            return dp[mask] = INF;
        }
        return dp[mask] = 1 + max_prev_dp;
    };

    int result = compute_dp((1 << n) - 1);

    if(result >= INF){
        cout << -1 << "\n";
    } else {
        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    return 0;
    
}
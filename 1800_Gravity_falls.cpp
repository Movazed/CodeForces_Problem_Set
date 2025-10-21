#include<bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define v_int vector<int>
#define v_v_int vector<vector<int>>
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve(){
    int n;
    cin >> n;
    v_v_int arrays(n);
    int max_len = 0;

    rep(i, 0, n) {
        int k;
        cin >> k;
        arrays[i].resize(k);
        if(k > max_len){
            max_len = k;
        }
        rep(j, 0, k) {
            cin >> arrays[i][j];
        }
    }

    sort(all(arrays));

    if(n == 0){
        cout << "\n";
        return;
    }

    v_int bottom_row(max_len);
    vector<bool> is_filled(max_len, false);
    int filled_count = 0;
    rep(i, 0, n){
        rep(j, 0, arrays[i].size()){
            if(!is_filled[j]){
                bottom_row[j] = arrays[i][j];
                is_filled[j] = true;
                filled_count++;
            }
        }

        if(filled_count == max_len){
            break;
        }
    }
    rep(i, 0, max_len){
        cout << bottom_row[i] << (i == max_len - 1 ? " " : " ");
    }
    cout << "\n";
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    string current_str;
    if (sz(s) > 0 && k > 0) {
        current_str.reserve(sz(s) * k);
    }
    for (int i = 0; i < k; ++i) {
        current_str += s;
    }

    while (sz(current_str) > 1) {
        // Operation 1: Remove alternate from the beginning
        string next_str = "";
        for (size_t i = 1; i < sz(current_str); i += 2) {
            next_str += current_str[i];
        }
        current_str = next_str;
        
        if (sz(current_str) <= 1) {
            break;
        }
        
        // Operation 2: Remove alternate from the end
        next_str = "";
        int len = sz(current_str);
        for (int i = 0; i < len; ++i) {
            // Keep if index from the end is odd. (len - 1 - i) is the index from the end.
            if (((len - 1 - i) & 1)) {
                next_str += current_str[i];
            }
        }
        current_str = next_str;
    }

    cout << current_str << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
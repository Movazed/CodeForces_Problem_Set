#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#endif
using namespace std;
using ll = long long;
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
const int MAXN = 4 * 1e4+5;

bool ispal(string s){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] != s[n-i-1]){
			return false;
		}
	}
	return true;
}

void solve() {
    vector<int> palin;
    for(int i = 1; i <= MAXN; i++){
    	if(ispal(to_string(i))){
    		palin.push_back(i);
    	}
    	
    }
    vector<int> dp(MAXN);
    dp[0] = 1;
   	for(int i: palin){
   		for(int j = i; j < MAXN; j++){
   			dp[j] = (dp[j] + dp[j-i]) % MOD;
   		}
   	}
   	int q; cin >> q;
   	while(q--){
   		int x; cin >> x;
   		cout << dp[x] << endl;
   	}
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}

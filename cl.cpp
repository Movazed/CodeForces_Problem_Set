#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

static inline long long calcCost(const string &s, char ch){
    vector<int> pos; pos.reserve(s.size());
    for(int i=0;i<(int)s.size();++i) if(s[i]==ch) pos.push_back(i);
    int m = (int)pos.size();
    if(m<=1) return 0;                         
    vector<int> z; z.reserve(m);
    for(int k=0;k<m;++k) z.push_back(pos[k]-k);
    nth_element(z.begin(), z.begin()+m/2, z.end());
    int med = z[m/2];
    long long ans = 0;
    for(int v: z) ans += ll(abs(v - med));
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n; string s;
        cin>>n>>s;
        long long x = calcCost(s,'a');
        long long y = calcCost(s,'b');
        cout << min(x,y) << "\n";
    }
    return 0;
}
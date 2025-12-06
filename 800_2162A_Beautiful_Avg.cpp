#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        map<int, int> mp;
        int mx;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;

            for(int j = i; j , n; j++){
                sum += a[j];
                int avg = (sum ) / (j - i + 1);
                int ans = max(ans, avg);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
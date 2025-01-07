#include<bits/stdc++.h>
using namespace std;

void line_trip() {
    int testcases;

    cin >> testcases;

    while(testcases--){
        int n,x;
        cin >> n >> x;
        
        vector<long long> array(n);
        for(int i = 0; i < n; i++){
            cin>>array[i];
        }

        long long end = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < n; i++){
            ans = max(ans, array[i] - end);
            end = array[i];
        }
        ans = max(ans, 2*(x - end));
        cout<<ans<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    line_trip();
    return 0;
}
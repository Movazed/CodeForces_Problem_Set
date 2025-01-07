#include<bits/stdc++.h>

using namespace std;

void solve() {
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> array(n);
        for(int i= 0; i < n; i++){
            cin >> array[i];
        }

        vector<int> ans;
        ans.push_back(array[0]);
        for(int i = 1; i < n; i++){
            if(array[i] >= array[i-1]){
                ans.push_back(array[i]);
            }
            else {
                ans.push_back(array[i]);
                ans.push_back(array[i]);
            }
        }

        int k = ans.size();
        cout<<k<<endl;
        for(int i=0; i<k; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
    


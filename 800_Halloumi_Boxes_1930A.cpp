#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long testcases;
    cin >> testcases;

    while (testcases--)
    {
        /* code */
        long long n, k;
        cin>> n >> k;

        vector<long long> array(n);

        for(long long i = 0; i < n; i++){
            cin >> array[i];
        }

        if(k <= 1 && !is_sorted(array.begin(), array.end())){
            cout << "NO"<< endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
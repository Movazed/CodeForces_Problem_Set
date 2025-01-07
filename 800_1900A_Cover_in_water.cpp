#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

#define vector <int, int> vii
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
typedef long long ll;
#define nl std::endl

using namespace std;

void cover_in_water() {
    ll testcases;
    cin >> testcases;

    while(testcases--){
        ll number_of_inputs;
        cin >> number_of_inputs;
        
        string str;
        cin >> str;

        ll count = 0;
        ll ans = 0;

        LOOP(i, number_of_inputs)
        {
            if(str[i] == '.'){
                count++;
                ans++;
            } else {
                count = 0;
            }

            if(count >= 3){
                break;
            }
        }

        if(count >= 3){
            cout << 2 << nl;
        } else{
            cout << ans << nl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cover_in_water();
    return 0;
}
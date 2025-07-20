#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long int ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)

#define mx 10000007
#define mod 1000000007
#define PI acos(-1.0)

int main()
{
    ll num, tc, k;

    sc1(tc);

    while (tc--){

        sc1(num);

        vector < pair <pair<ll, ll>, ll> > vcp(num);

        vector <ll> ans(num);

        for(ll i = 0; i < num; i++){
            cin >> vcp[i].first.first >> vcp[i].first.second;
            vcp[i].second = i;
        }

        bool check = false;

        sort(vcp.begin(), vcp.end());

        ll mx1 = 0;

        for(ll i = 0; i < num; i++){

            if(i != 0 && mx1 < vcp[i].first.first){

                for(ll j = 0; j < i; j++)
                    ans[vcp[j].second] = 1;

                for(ll j = i; j < num; j++)
                    ans[vcp[j].second] = 2;
                check = true;
                break;
            }

            mx1 = max(mx1, vcp[i].first.second);
        }

        if(check == false) cout << "-1" << endl;
        else{

            for(ll i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}
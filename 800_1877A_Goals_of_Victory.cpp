#include<bits/stdc++.h>
#include <vector>
#include <stack>
#define nl std::endl
typedef long double ld;
typedef long long ll;
#define vi vector <int>
#define pair <int int> pii
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
#define PRINT std::cout
using namespace std;

void goals() {

    ll testcases;
    cin >> testcases;

    while (testcases--)
    {
        ll n;
        cin >> n;

        ll sum = 0;
        for(ll i = 0; i < n-1; i++){
            ll temp;
            cin >> temp;

            sum += temp;

        }
        cout << -(sum) << endl;
    }
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    goals();
    return 0;
}


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

void target_practice() {
    ll testcases = 1;
    cin >> testcases;

    while (testcases--)
    {
        ll scoreBoard[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,1,1,1,1,1,1,1,1,1}
        };

        ll score = 0;

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                char ch;
                cin >> ch;

                if(ch != '.')
                {
                    score += scoreBoard[i][j];
                }

            }
        }
            cout << score << nl;
    
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    target_practice();
    return 0;
}
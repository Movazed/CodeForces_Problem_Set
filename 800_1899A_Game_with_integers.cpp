#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define nl std::endl
typedef long double ld;
typedef long long ll;

#define vector <int, int> vii
#define pair <int int> pii
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
#define print std::cout
using namespace std;

void game_with_intgers()
{
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        int number;
        cin >> number;

        for (int i = 0; i <= 10; i++)
        {
            if ((number + 1) % 3 == 0 || (number - 1) % 3 == 0)
            {
                print << "First" << nl;
                break;
            }
            if ((number + 1) % 3 != 0 || (number - 1) % 3 != 0)
            {
                print << "Second" << nl;
                break;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    game_with_intgers();
    return 0;
}
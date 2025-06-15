#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define nl std::endl
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define ar array
#define ll long long
#define ld long double
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define PRINT std::cout 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAX_FACT = 1e5 + 5;  // Maximum size for factorials
int fact[MAX_FACT], ifact[MAX_FACT];


// Constants
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l,r)(rng); }


struct Node {
    int zero, one;
    Node(int a = 0, int b = 0) : zero(a), one(b) {}
};

class SegmentTree {
public:
    vector<Node> tree;
    vector<int> lazy;
    int n;

    SegmentTree(vector<int>& arr, string& str) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1, str);
    }

    Node combine(Node a, Node b) {
        return Node(a.zero ^ b.zero, a.one ^ b.one);
    }

    void build(vector<int>& arr, int cur, int s, int e, string& str) {
        if (s == e) {
            if (str[s] == '0') {
                tree[cur] = Node(arr[s], 0);
            } else {
                tree[cur] = Node(0, arr[s]);
            }
            return;
        }
        int mid = (s + e) / 2;
        build(arr, 2 * cur, s, mid, str);
        build(arr, 2 * cur + 1, mid + 1, e, str);
        tree[cur] = combine(tree[2 * cur], tree[2 * cur + 1]);
    }

    void push(int cur, int s, int e) {
        if (lazy[cur]) {
            swap(tree[cur].zero, tree[cur].one);
            if (s != e) {
                lazy[2 * cur] ^= 1;
                lazy[2 * cur + 1] ^= 1;
            }
            lazy[cur] = 0;
        }
    }

    void update(int cur, int s, int e, int l, int r) {
        push(cur, s, e);
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            lazy[cur] ^= 1;
            push(cur, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(2 * cur, s, mid, l, r);
        update(2 * cur + 1, mid + 1, e, l, r);
        tree[cur] = combine(tree[2 * cur], tree[2 * cur + 1]);
    }

    void update(int l, int r) {
        update(1, 0, n - 1, l, r);
    }

    int query(int g) {
        return g ? tree[1].one : tree[1].zero;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr) {
            cin >> i;
        }
        string str;
        cin >> str;
        SegmentTree st(arr, str);
        int q;
        cin >> q;
        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                --l, --r;
                st.update(l, r);
            } else {
                int g;
                cin >> g;
                cout << st.query(g) << ' ';
            }
        }
        cout << nl;
    }
    return 0;
}

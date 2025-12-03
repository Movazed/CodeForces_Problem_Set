#include <x86intrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

namespace io {
    template<typename First, typename Second>
    ostream &operator<<(ostream &os, const pair<First, Second> &p) { return os << p.first << " " << p.second; }

    template<typename First, typename Second>
    ostream &operator<<(ostream &os, const map<First, Second> &mp) {
        for (auto it: mp) {
            os << it << endl;
        }
        return os;
    }

    template<typename First>
    ostream &operator<<(ostream &os, const vector<First> &v) {
        bool space = false;
        for (First x: v) {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }

    template<typename First>
    ostream &operator<<(ostream &os, const set<First> &st) {
        bool space = false;
        for (First x: st) {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }

    template<typename First>
    ostream &operator<<(ostream &os, const multiset<First> &st) {
        bool space = false;
        for (First x: st) {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }

    template<typename First, typename Second>
    istream &operator>>(istream &is, pair<First, Second> &p) { return is >> p.first >> p.second; }

    template<typename First>
    istream &operator>>(istream &is, vector<First> &v) {
        for (First &x: v) {
            is >> x;
        }
        return is;
    }

    long long fastread() {
        char c;
        long long d = 1, x = 0;
        do
            c = getchar();
        while (c == ' ' || c == '\n');
        if (c == '-')
            c = getchar(), d = -1;
        while (isdigit(c)) {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return d * x;
    }

    static bool sep = false;

    using std::to_string;

    string to_string(bool x) { return (x ? "true" : "false"); }

    string to_string(const string &s) { return "\"" + s + "\""; }

    string to_string(const char *s) { return "\"" + string(s) + "\""; }

    string to_string(const char &c) {
        string s;
        s += c;
        return "\'" + s + "\'";
    }

    template<typename Type>
    string to_string(vector<Type>);

    template<typename First, typename Second>
    string to_string(pair<First, Second>);

    template<typename Collection>
    string to_string(Collection);

    template<typename First, typename Second>
    string to_string(pair<First, Second> p) { return "{" + to_string(p.first) + ", " + to_string(p.second) + "}"; }

    template<typename Type>
    string to_string(vector<Type> v) {
        bool sep = false;
        string s = "[";
        for (Type x: v) {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "]";
        return s;
    }

    template<typename Collection>
    string to_string(Collection collection) {
        bool sep = false;
        string s = "{";
        for (auto x: collection) {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "}";
        return s;
    }

    void print() {
        cerr << endl;
        sep = false;
    }

    template<typename First, typename... Other>
    void print(First first, Other... other) {
        if (sep)
            cerr << " | ";
        sep = true;
        cerr << to_string(first);
        print(other...);
    }
}
using namespace io;

// DEBUG BEGIN
#ifndef ONLINE_JUDGE

template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<class Tuple, size_t N>
struct _tuple_printer {
    static ostream &_print(ostream &out, const Tuple &t) {
        return _tuple_printer<Tuple, N - 1>::_print(out, t) << ", " << get<N - 1>(t);
    }
};

template<class Tuple>
struct _tuple_printer<Tuple, 1> {
    static ostream &_print(ostream &out, const Tuple &t) { return out << get<0>(t); }
};

template<class... Args>
ostream &_print_tuple(ostream &out, const tuple<Args...> &t) {
    return _tuple_printer<decltype(t), sizeof...(Args)>::_print(out << "{", t) << "}";
}

template<class... Args>
ostream &operator<<(ostream &out, const tuple<Args...> &t) {
    return _print_tuple(out, t);
}

template<class T>
ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr) {
    if (arr.empty())
        return out << "{}";
    out << "{";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        out << *it;
        next(it) != arr.end() ? out << ", " : out << "}";
    }
    return out;
}

ostream &operator<<(ostream &out, const _Bit_reference &bit) {
    return out << bool(bit);
}

template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq) {
    vector<T> a;
    while (!pq.empty())
        a.push_back(pq.top()), pq.pop();
    return out << a;
}

template<class Head>
void debug_out(Head H) { cerr << H << endl; }

template<class Head, class... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ", ", debug_out(T...); }

void debug2_out() {}

template<class Head, class... Tail>
void debug2_out(Head H, Tail... T) {
    cerr << "\n";
    for (auto x: H)
        cerr << x << ",\n";
    debug2_out(T...);
}

template<class Width, class Head>
void debugbin_out(Width w, Head H) {
    for (auto rep = w; rep; --rep, H >>= 1)
        cerr << (H & 1);
    cerr << endl;
}

template<class Width, class Head, class... Tail>
void debugbin_out(Width w, Head H, Tail... T) {
    for (auto rep = w; rep; --rep, H >>= 1)
        cerr << (H & 1);
    cerr << ", ";
    debugbin_out(w, T...);
}

enum CODE {
    CCRED = 31,
    CCGREEN = 32,
    CCYELLOW = 33,
    CCBLUE = 34,
    CCDEFAULT = 39
};
#define debug_endl() cerr << endl
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m"
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m"
#define debugbin(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debugbin_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m"
#else
#define debug_endl() 42
#define debug(...) 42
#define debug2(...) 42
#define debugbin(...) 42
#endif

// DEBUG END

#define ll long long
#define pll pair<ll, ll>
#define vt vector
#define pb push_back
#define ar array
#define str string

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define rep(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define each(x, a) for (auto &x : a)
#define all(a) a.begin(), a.end()
#define r_each(x, a) for (auto &x : a | views::reverse)
#define len(a) a.size()

bool prime(ll a) {
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

template<class T>
struct graph {
    struct E {
        int from, to;
        T cost;
    };
    int n;
    vector<E> edge;
    vector<vector<int>> adj;
    function<bool(int)> ignore;

    graph(int n = 1) : n(n), adj(n) {
        assert(n >= 1);
    }

    graph(const vector<vector<int>> &adj, bool undirected = true) : n((int) adj.size()), adj(n) {
        assert(n >= 1);
        if (undirected) {
            for (auto u = 0; u < n; ++u) for (auto v: adj[u]) if (u < v) link(u, v);
        } else for (auto u = 0; u < n; ++u) for (auto v: adj[u]) orient(u, v);
    }

    graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true) : n((int) adj.size()), adj(n) {
        assert(n >= 1);
        if (undirected) {
            for (auto u = 0; u < n; ++u) for (auto [v, w]: adj[u]) if (u < v) link(u, v, w);
        } else for (auto u = 0; u < n; ++u) for (auto [v, w]: adj[u]) orient(u, v, w);
    }

    graph(int n, vector<array<int, 2>> &edge, bool undirected = true) : n(n), adj(n) {
        assert(n >= 1);
        for (auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
    }

    graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true) : n(n), adj(n) {
        assert(n >= 1);
        for (auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
    }

    int operator()(int u, int id) const {
#ifdef LOCAL
        assert(0 <= id && id < (int)edge.size());
        assert(edge[id].from == u || edge[id].to == u);
#endif
        return u ^ edge[id].from ^ edge[id].to;
    }

    int link(int u, int v, T w = {}) { // insert an undirected edge
        int id = (int) edge.size();
        adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
        return id;
    }

    int orient(int u, int v, T w = {}) { // insert a directed edge
        int id = (int) edge.size();
        adj[u].push_back(id), edge.push_back({u, v, w});
        return id;
    }

    graph transposed() const { // the transpose of the directed graph
        graph res(n);
        for (auto &e: edge) res.orient(e.to, e.from, e.cost);
        res.ignore = ignore;
        return res;
    }

    int degree(int u) const { // the degree (outdegree if directed) of u (without the ignoration rule)
        return (int) adj[u].size();
    }

    // The adjacency list is sorted for each vertex.
    vector<vector<int>> get_adjacency_list() const {
        vector<vector<int>> res(n);
        for (auto u = 0; u < n; ++u)
            for (auto id: adj[u]) {
                if (ignore && ignore(id)) continue;
                res[(*this)(u, id)].push_back(u);
            }
        return res;
    }

    void set_ignoration_rule(const function<bool(int)> &f) {
        ignore = f;
    }

    void reset_ignoration_rule() {
        ignore = nullptr;
    }

    friend ostream &operator<<(ostream &out, const graph &g) {
        for (auto id = 0; id < (int) g.edge.size(); ++id) {
            if (g.ignore && g.ignore(id)) continue;
            auto &e = g.edge[id];
            out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
        }
        return out;
    }
};

template<class T>
struct dfs_forest {
    int n;
    vector<T> dist;
    vector<int> pv;
    vector<int> pe;
    vector<int> order;
    vector<int> pos;
    vector<int> end;
    vector<int> size;
    vector<int> root;
    vector<int> depth;
    vector<int> min_depth;
    vector<int> min_depth_origin;
    vector<int> min_depth_spanning_edge;
    vector<int> was;
    T T_id;

    dfs_forest(int n, T T_id = 0) : T_id(T_id) { init(n); }

    void init(int n) {
        this->n = n;
        pv.assign(n, -1);
        pe.assign(n, -1);
        order.clear();
        pos.assign(n, -1);
        end.assign(n, -1);
        size.assign(n, 0);
        root.assign(n, -1);
        depth.assign(n, -1);
        min_depth.assign(n, -1);
        min_depth_origin.assign(n, -1);
        min_depth_spanning_edge.assign(n, -1);
        dist.assign(n, T_id);
        was.assign(n, -1);
        attempt = 0;
    }

    int attempt;

    // O(n + m)
    // Requires graph
    template<class Graph, class F = plus<>>
    void dfs(const Graph &g, int u, bool clear_order = true, F UT = plus<>()) {
        assert(n == g.n);
        ++attempt;
        depth[u] = 0;
        dist[u] = T_id;
        root[u] = u;
        pv[u] = pe[u] = -1;
        if (clear_order) order.clear();
        auto recurse = [&](auto self, int u) -> void {
            was[u] = attempt;
            pos[u] = (int) order.size();
            order.push_back(u);
            size[u] = 1;
            min_depth[u] = depth[u];
            min_depth_origin[u] = u;
            min_depth_spanning_edge[u] = -1;
            for (auto id: g.adj[u]) {
                if (id == pe[u] || g.ignore && g.ignore(id)) continue;
                auto &e = g.edge[id];
                int v = e.from ^ e.to ^ u;
                if (was[v] == attempt) {
                    if (min_depth[u] > depth[v]) {
                        min_depth[u] = depth[v];
                        min_depth_spanning_edge[u] = id;
                    }
                    continue;
                }
                depth[v] = depth[u] + 1;
                dist[v] = UT(e.cost, dist[u]);
                pv[v] = u;
                pe[v] = id;
                root[v] = root[u];
                self(self, v);
                size[u] += size[v];
                if (min_depth[u] > min_depth[v]) {
                    min_depth[u] = min_depth[v];
                    min_depth_origin[u] = min_depth_origin[v];
                    min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
                }
            }
            end[u] = (int) order.size();
        };
        recurse(recurse, u);
    }

    // O(n + m)
    template<class Graph, class F = plus<>>
    void dfs_all(const Graph &g, F UT = plus<>()) {
        for (auto u = 0; u < n; ++u) if (!~depth[u]) dfs<Graph, F>(g, u, false, UT);
    }

    // O(n + m)
    template<class F = plus<>>
    void dfs_implicitly(auto get_deg, auto get_adj, int u, bool clear_order = true, F UT = plus<>()) {
        ++attempt;
        depth[u] = 0;
        dist[u] = T_id;
        root[u] = u;
        pv[u] = pe[u] = -1;
        if (clear_order) order.clear();
        auto recurse = [&](auto self, int u) -> void {
            was[u] = attempt;
            pos[u] = (int) order.size();
            order.push_back(u);
            size[u] = 1;
            min_depth[u] = depth[u];
            min_depth_origin[u] = u;
            min_depth_spanning_edge[u] = -1;
            for (auto i = 0, deg = get_deg(u); i < deg; ++i) {
                auto [v, w] = get_adj(u, i);
                if (!~v) continue;
                if (was[v] == attempt) {
                    if (min_depth[u] > depth[v]) {
                        min_depth[u] = depth[v];
                        min_depth_spanning_edge[u] = i;
                    }
                    continue;
                }
                depth[v] = depth[u] + 1;
                dist[v] = UT(w, dist[u]);
                pv[v] = u;
                pe[v] = i;
                root[v] = root[u];
                self(self, v);
                size[u] += size[v];
                if (min_depth[u] > min_depth[v]) {
                    min_depth[u] = min_depth[v];
                    min_depth_origin[u] = min_depth_origin[v];
                    min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
                }
            }
            end[u] = (int) order.size();
        };
        recurse(recurse, u);
    }

    // O(n + m)
    template<class F = plus<>>
    void dfs_all_implicitly(auto get_deg, auto get_adj, F UT = plus<>()) {
        for (auto u = 0; u < n; ++u) if (!~depth[u]) dfs<F>(get_deg, get_adj, u, false, UT);
    }

    bool ancestor_of(int u, int v) const {
        return pos[u] <= pos[v] && end[v] <= end[u];
    }
};

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    graph<int> g(n);

    rep(n - 1) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        g.link(v1, v2, w);
    }

    a--, b--;

    dfs_forest<int> DFS(n);

    DFS.dfs(g, b);

    map<int, int> mp;
    vt<int> dp1(n, 0), dp2(n, 0);
    each(x, DFS.order) {
        if (x != b) mp[dp1[x]] = 1;
        each(id, g.adj[x]) {
            if (id == DFS.pe[x]) continue;
            dp1[g(x, id)] = (dp1[x] ^ g.edge[id].cost);
        }
    }


    DFS.dfs(g, a);
    each(x, DFS.order) {
        if (!DFS.ancestor_of(b,x) and mp[dp2[x]]) {
            cout << "Yes\n";
            return;
        }
        each(id,g.adj[x]){
            if (id == DFS.pe[x]) continue;
            dp2[g(x, id)] = (dp2[x] ^ g.edge[id].cost);
        }
    }

    cout<<"No\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
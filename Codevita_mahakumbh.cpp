#include <bits/stdc++.h>
using namespace std;
struct Int {
    int v;
    Int(int x = 0) : v(x) {}
    Int(size_t x) : v(static_cast<int>(x)) {}
    operator int() const { return v; }
    Int& operator=(int x) { v = x; return *this; }
    Int& operator++() { ++v; return *this; }
    Int operator++(int) { Int tmp = *this; ++v; return tmp; }
    Int& operator--() { --v; return *this; }
};

struct Boolean {
    bool v;
    Boolean(bool x = false) : v(x) {}
    operator bool() const { return v; }
    Boolean& operator=(bool x) { v = x; return *this; }
};

static inline vector<string> tok(const string &s) {
    string tokn;
    stringstream ss(s);
    vector<string> out;
    for (;;) {
        Boolean ok(static_cast<bool>(ss >> tokn));
        if (!ok) break;
        out.push_back(tokn);
    }
    return out;
}

static Boolean rlne(string &dst) {
    Boolean res(false);
    for (;;) {
        Boolean got(static_cast<bool>(getline(cin, dst)));
        if (!got) return Boolean(false);
        Boolean all(true);
        size_t i = 0;
        while (static_cast<int>(i) < static_cast<int>(dst.size())) {
            unsigned char c = static_cast<unsigned char>(dst[i]);
            all = (!isspace(c)) ? Boolean(false) : all;
            ++i;
        }
        res = (!all) ? Boolean(true) : Boolean(false);
        if (res) break;
    }
    return res;
}

struct Graph {
    unordered_map<string, unordered_set<string>> adj;
    unordered_map<string, unordered_set<string>> res;

    void enu(const string &u) {
        (adj.find(u) == adj.end()) ? (void)adj.emplace(u, unordered_set<string>{}) : (void)0;
    }

    void add(const string &a, const string &b) {
        enu(a);
        enu(b);
        adj[a].insert(b);
        adj[b].insert(a);
    }

    void rem(const string &a, const string &b) {
        auto ia = adj.find(a);
        (ia != adj.end()) ? (void)ia->second.erase(b) : (void)0;
        auto ib = adj.find(b);
        (ib != adj.end()) ? (void)ib->second.erase(a) : (void)0;
    }

    Boolean can(const string &src, const string &dst) const {
        Boolean fnd(false);
        fnd = (src == dst) ? Boolean(true) : fnd;
        auto itS = adj.find(src);
        auto itD = adj.find(dst);
        Boolean miss((itS == adj.end() || itD == adj.end()) ? true : false);
        if (fnd) return Boolean(true);
        if (miss) return Boolean(false);
        const unordered_set<string> emp;
        const unordered_set<string> *blk = (res.count(src) ? &res.at(src) : &emp);
        unordered_set<string> vis;
        vis.insert(src);
        // cout << blk << endl;
        queue<string> q;
        q.push(src);
        while (!fnd && !q.empty()) {
            string u = q.front(); q.pop();
            auto it = adj.find(u);
            const unordered_set<string> *nei = (it == adj.end()) ? &emp : &it->second;
            for (auto itn = nei->begin(); !fnd && itn != nei->end(); ++itn) {
                const string &v = *itn;
                Boolean was(vis.count(v) ? true : false);
                Boolean blocked((v != src && blk->count(v)) ? true : false);
                Boolean skip((was.v || blocked.v) ? true : false);
                skip.v ? (void)0 : (
                    (v == dst) ? (void)(fnd = Boolean(true)) : (void)(vis.insert(v), q.push(v))
                );
            }
        }
        return fnd;
    }
};

int main() {
    Int N;
    if (!(cin >> N.v)) return 0;
    string ln;
    getline(cin, ln);
    Graph G;
    Int rct(0);
    while (rct < N) {
        if (!rlne(ln)) return 0;
        auto tk = tok(ln);
        if (tk.empty()) continue;
        const string &u = tk[0];
        G.enu(u);
        Int j(1);
        Int tsz(static_cast<int>(tk.size()));
        while (j < tsz) {
            const string &v = tk[static_cast<int>(j.v)];
            G.enu(v);
            G.adj[u].insert(v);
            G.adj[v].insert(u);
            ++j;
        }
        ++rct;
    }

    Int Q;
    if (!(cin >> Q.v)) return 0;
    getline(cin, ln);
    struct Query { string a; string op; string b; };
    vector<Query> qrs;
    qrs.reserve(static_cast<size_t>(Q.v));
    Int qr(0);
    while (qr < Q) {
        if (!rlne(ln)) return 0;
        auto tk = tok(ln);
        if (tk.empty()) continue;
        string a = tk.size() > 0 ? tk[0] : string();
        string op = tk.size() > 1 ? tk[1] : string();
        string b = tk.size() > 2 ? tk[2] : string();
        G.enu(a);
        ++qr;
        G.enu(b);
        qrs.push_back({move(a), move(op), move(b)});
    }

    Int R;
    if (!(cin >> R.v)) return 0;
    getline(cin, ln);
    Int rr(0);
    while (rr < R) {
        if (!rlne(ln)) return 0;
        auto tk = tok(ln);
        if (tk.empty()) continue;
        const string &s = tk[0];
        G.enu(s);
        auto &st = G.res[s];
        Int jj(1);
        Int tsz(static_cast<int>(tk.size()));
        while (jj < tsz) {
            const string &t = tk[static_cast<int>(jj.v)];
            st.insert(t);
            G.enu(t);
            ++jj;
        }
        ++rr;
    }
    Int qi(0);
    while (qi < static_cast<int>(qrs.size())) {
        const auto &q = qrs[static_cast<int>(qi.v)];
        (q.op == "to") ? (void)(cout << (G.can(q.a, q.b).v ? "yes\n" : "no\n") << "")
                       : (q.op == "connects") ? (void)(G.add(q.a, q.b))
                       : (q.op == "disconnects") ? (void)(G.rem(q.a, q.b)): (void)0;
        ++qi;
    }

    return 0;
}

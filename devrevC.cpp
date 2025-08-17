#include <vector>
#include <functional>
using namespace std;

vector<int> solve(int N, int Q, vector<vector<int>> query) {
    struct Node { int mx, idx; };
    const int INF = 1e9;

    int size = 4 * N;
    vector<int> lazy(size, 0);
    vector<Node> st(size);

    auto merge = [&](const Node& a, const Node& b) -> Node {
        if (a.mx > b.mx) return a;
        if (b.mx > a.mx) return b;
        return {a.mx, min(a.idx, b.idx)};
    };

    function<void(int, int, int)> build = [&](int p, int l, int r) {
        lazy[p] = 0;
        if (l == r) { st[p] = {0, l}; return; }
        int m = (l + r) >> 1;
        build(p<<1, l, m);
        build(p<<1|1, m+1, r);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    };

    auto apply = [&](int p, int val) {
        st[p].mx += val;
        lazy[p] += val;
    };

    function<void(int)> push = [&](int p) {
        if (lazy[p] != 0) {
            apply(p<<1, lazy[p]);
            apply(p<<1|1, lazy[p]);
            lazy[p] = 0;
        }
    };

    function<void(int, int, int, int, int, int)> update = [&](int p, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { apply(p, val); return; }
        push(p);
        int m = (l + r) >> 1;
        update(p<<1, l, m, ql, qr, val);
        update(p<<1|1, m+1, r, ql, qr, val);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    };

    function<Node(int, int, int, int, int)> querySeg = [&](int p, int l, int r, int ql, int qr) -> Node {
        if (ql > r || qr < l) return Node{-INF, INF};
        if (ql <= l && r <= qr) return st[p];
        push(p);
        int m = (l + r) >> 1;
        Node left = querySeg(p<<1, l, m, ql, qr);
        Node right = querySeg(p<<1|1, m+1, r, ql, qr);
        return merge(left, right);
    };

    build(1, 1, N);

    vector<int> ans;
    ans.reserve(Q);

    for (int i = 0; i < Q; ++i) {
        int type = query[i][0];
        int x = query[i][1];

        if (type == 1) {
            update(1, 1, N, 1, x, 1);
        } else if (type == 2) {
            update(1, 1, N, x, N, 1);
        } else if (type == 3) {
            Node res = querySeg(1, 1, N, x, N);
            ans.push_back(res.idx);
        }
    }
    return ans;
}
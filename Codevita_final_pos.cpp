#include <bits/stdc++.h>
using namespace std;

struct Int {
    long long v;
    Int(long long x = 0) : v(x) {}
    operator long long() const { return v; }
    Int& operator+=(const Int &o) { v += o.v; return *this; }
    Int& operator-=(const Int &o) { v -= o.v; return *this; }
    Int& operator++() { ++v; return *this; }
    Int operator++(int) { Int t = *this; ++v; return t; }
    Int& operator--() { --v; return *this; }
    friend Int operator+(Int a, const Int &b) { a += b; return a; }
    friend Int operator-(Int a, const Int &b) { a -= b; return a; }
    friend bool operator<(const Int &a, const Int &b) { return a.v < b.v; }
    friend bool operator>(const Int &a, const Int &b) { return a.v > b.v; }
    friend bool operator<=(const Int &a, const Int &b) { return a.v <= b.v; }
    friend bool operator>=(const Int &a, const Int &b) { return a.v >= b.v; }
    friend bool operator==(const Int &a, const Int &b) { return a.v == b.v; }
    friend bool operator!=(const Int &a, const Int &b) { return a.v != b.v; }
};

struct Double {
    double v;
    Double(double x = 0.0) : v(x) {}
    operator double() const { return v; }
    Double& operator+=(const Double &o) { v += o.v; return *this; }
    Double& operator-=(const Double &o) { v -= o.v; return *this; }
    friend Double operator+(Double a, const Double &b) { a += b; return a; }
    friend Double operator-(Double a, const Double &b) { a -= b; return a; }
    friend Double operator*(Double a, const Double &b) { return Double(a.v * b.v); }
    friend Double operator/(Double a, const Double &b) { return Double(a.v / b.v); }
    friend bool operator<(const Double &a, const Double &b) { return a.v < b.v; }
    friend bool operator>(const Double &a, const Double &b) { return a.v > b.v; }
    friend bool operator<=(const Double &a, const Double &b) { return a.v <= b.v; }
    friend bool operator>=(const Double &a, const Double &b) { return a.v >= b.v; }
    friend bool operator==(const Double &a, const Double &b) { return a.v == b.v; }
    friend bool operator!=(const Double &a, const Double &b) { return a.v != b.v; }
};

struct Bool {
    bool v;
    Bool(bool x = false) : v(x) {}
    operator bool() const { return v; }
    friend Bool operator!(const Bool &b) { return Bool(!b.v); }
};

static constexpr double tmp = 1e-9;

inline Bool dbl_eq(const Double &u, const Double &v) {
    return Bool(fabs(u.v - v.v) < tmp);
}

inline Int LongLongDouble(const Double &d) {
    return Int(llround(d.v));
}

inline Int sgn_d(const Double &x) {
    return Double(x.v) > Double(tmp) ? Int(1) : (Double(x.v) < Double(-tmp) ? Int(-1) : Int(0));
}

struct AC {
    Double x; Double y;
    AC(Double _x = 0.0, Double _y = 0.0) : x(_x), y(_y) {}
};

struct AB {
    Double c;
    AC a;AC b;
    AC lo;AC hi;
    Int slp;Int id;
    AB() : id(0), a(), b(), lo(), hi(), slp(0), c(0.0) {}
};

inline Double absd(const Double &x) { return Double(fabs(x.v)); }

bool dp4(const AC &p, const AC &u, const AC &v) {
    Bool xok = Bool(p.x.v + tmp >= min(u.x.v, v.x.v) && p.x.v - tmp <= max(u.x.v, v.x.v));
    Bool yok = Bool(p.y.v + tmp >= min(u.y.v, v.y.v) && p.y.v - tmp <= max(u.y.v, v.y.v));
    return Bool(xok.v && yok.v).v;
}

bool dp3(const AC &p, const AB &s) {
    Bool eq = dbl_eq(p.y, Double(s.slp.v * p.x.v + s.c.v));
    return Bool(eq.v && dp4(p, s.a, s.b)).v;
}

AC inter(const AB &s1, const AB &s2) {
    Double dnm = Double(double(s1.slp.v - s2.slp.v));
    Double x = Double((s2.c.v - s1.c.v) / dnm.v);
    Double y = Double(s1.slp.v * x.v + s1.c.v);
    return AC(x, y);
}

Double d2p(const AC &p1, const AC &p2) {
    Double dx = Double(p1.x.v - p2.x.v);
    Double dy = Double(p1.y.v - p2.y.v);
    return Double(dx.v*dx.v + dy.v*dy.v);
}

int main() {
    Int n;
    Bool rok = Bool(bool(cin >> n.v));
    if (!rok.v) return 0;
    vector<AB> sld;
    sld.reserve((size_t)(long long)n.v);
    Int i = 0;
    while (i < n) {
        AB s;
        s.id = i;
        cin >> s.a.x.v >> s.a.y.v >> s.b.x.v >> s.b.y.v;
        (s.a.y.v < s.b.y.v) ? (s.lo = s.a, s.hi = s.b) : (s.lo = s.b, s.hi = s.a);
        double dx = s.b.x.v - s.a.x.v;
        double dy = s.b.y.v - s.a.y.v;
        double r = fabs(dx) < 1e-18 ? (dy >= 0.0 ? 1.0 : -1.0) : (dy / dx);
        s.slp = Int(r > 0.0 ? 1 : -1);
        s.c = Double(s.a.y.v - s.slp.v * s.a.x.v);
        sld.push_back(s);
        ++i;
}
 
    AC cur;
    cin >> cur.x.v >> cur.y.v;
    auto temp = [&](const AC &p) -> Int {
        Int c = 0;
        Int k = 0;
        while (k < Int((long long)sld.size())) {
            const AB &s = sld[(size_t)k.v];
            c = c + (dp3(p, s) ? Int(1) : Int(0));
            ++k;
        }
        return c;
    };
    (temp(cur).v >= 2) ? (cout << LongLongDouble(cur.x).v << " " << LongLongDouble(cur.y).v << "\n", (void)0) : (void)0;
    if (temp(cur).v >= 2) return 0;

    for (;;) {
        AC bh = AC(Double(-1.0), Double(-1.0));
        Int bid = Int(-1);

        Int k = 0;
        while (k < Int((long long)sld.size())) {
            const AB &s = sld[(size_t)k.v];
            Bool inr = Bool(!(cur.x.v + tmp < min(s.a.x.v, s.b.x.v) || cur.x.v - tmp > max(s.a.x.v, s.b.x.v)));
            if (!inr.v) { ++k; continue; }
            Double yx = Double(s.slp.v * cur.x.v + s.c.v);
            AC can = AC(cur.x, yx);
            Bool ons = Bool(dp4(can, s.a, s.b));
            Bool bel = Bool(yx.v < cur.y.v - tmp);
            if (!ons.v || !bel.v) { ++k; continue; }
            (bid.v == -1 || yx.v > bh.y.v + tmp) ? (void)(bh = can, bid = s.id) : (void)0;
            ++k;
        }
        if (bid.v == -1) {
            cur.y = Double(0.0);
            break;
        }
        cur = bh;
        if (temp(cur).v >= 2) break;
        const AB &ls = sld[(size_t)bid.v];
        AC dst = ls.lo;
        if (dbl_eq(cur.x, dst.x).v && dbl_eq(cur.y, dst.y).v) { continue; }
        AC ni = AC(Double(-1.0), Double(-1.0));
        Double bds = Double(numeric_limits<double>::infinity());
        Int j = 0;
        while (j < Int((long long)sld.size())) {
            const AB &o = sld[(size_t)j.v];
            if (o.id.v == ls.id.v) { ++j; continue; }
            if (o.slp.v == ls.slp.v) { ++j; continue; }
            AC it = inter(ls, o);
            if (!dp4(it, o.a, o.b)) { ++j; continue; }
            if (!dp4(it, cur, dst)) { ++j; continue; }
            if (d2p(it, cur).v < tmp*tmp) { ++j; continue; }
            Double d2 = d2p(it, cur);
            (d2.v < bds.v - tmp) ? (void)(bds = d2, ni = it) : (void)0;
            ++j;
        }
        if (ni.x.v > -0.5) {
            cur = ni;
            break;
        } else {
            cur = dst;
        }
    }
    cout << LongLongDouble(cur.x).v << " " << LongLongDouble(cur.y).v << ""; 
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
struct Int {
    int v;
    Int(): v(0) {}
    Int(int x): v(x) {}
    operator int() const { return v; }
    Int& operator=(int x) { v = x; return *this; }
    Int& operator+=(int x) { v += x; return *this; }
    Int& operator-=(int x) { v -= x; return *this; }
    Int& operator++() { ++v; return *this; }
    Int operator++(int) { Int t = *this; v++; return t; }
    bool operator<(const Int& o) const { return v < o.v; }
    bool operator==(const Int& o) const { return v == o.v; }
    bool operator!=(const Int& o) const { return v != o.v; }
    friend ostream& operator<<(ostream& os, const Int& I) { os << I.v; return os; }
    friend istream& operator>>(istream& is, Int& I) { is >> I.v; return is; }
};
struct LongLong {
    Int exi;
    Int neu;
    string dir;
};
bool Seg(const LongLong& a, const LongLong& b) {
    return (a.exi != b.exi) ? (a.exi < b.exi) : (a.neu < b.neu);
}

class Solve {
private:
    map<pair<Int,Int>, Int> gri;
    map<Int, pair<Int,Int>> pos;
    pair<Int,Int> temp(const pair<Int,Int>& cur, const string& dir) {
        return dir == "right" ? pair<Int,Int>{ Int(int(cur.first) + 1), cur.second }
             : dir == "left"  ? pair<Int,Int>{ Int(int(cur.first) - 1), cur.second }
             : dir == "top"   ? pair<Int,Int>{ cur.first, Int(int(cur.second) + 1) }
             : pair<Int,Int>{ cur.first, Int(int(cur.second) - 1) };
    }

    void psl(Int cub, const pair<Int,Int>& posi) {
        gri.count(posi) ? pos.erase(gri[posi]) : 0;
        gri[posi] = cub;
        pos[cub] = posi;
    }

public:
    void dp2(const vector<LongLong>& cmd) {
        auto it = cmd.begin();
        cout << " ";
        while (it != cmd.end()) {
            const LongLong& c = *it;
            Int exi = c.exi;
            Int neu = c.neu;
            (!pos.count(exi)) ? (psl(exi, pair<Int,Int>{ Int(0), Int(0) }), 0) : 0;
            // cout << pos << endl;
            pair<Int,Int> cur = pos[exi];
            pair<Int,Int> np = temp(cur, c.dir);
            pos.count(neu) ? gri.erase(pos[neu]) : 0;
            psl(neu, np);
            ++it;
        }
    }
    void dp1(Int tar) {
        pos.count(tar)
            ? ([&]()->int {
                  pair<Int,Int> p = pos[tar];
                  // cout << p << endl;
                  vector<pair<Int,Int>> nei = {
                      { p.first, Int(int(p.second) + 1) },
                      { p.first, Int(int(p.second) - 1) },
                      { Int(int(p.first) - 1), p.second },
                      { Int(int(p.first) + 1), p.second }
                  };
                  Int i = 0;
                  cout << " ";
                  while (int(i) < int(nei.size())) {
                      cout << (gri.count(nei[int(i)]) ? gri[nei[int(i)]] : Int(-1));
                      (int(i) + 1 < int(nei.size())) ? ((cout << " "), 0) : 0;
                      ++i;
                  }
                  cout << "";
                  return 0;
              }(), 0)
            : (cout << "-1 -1 -1 -1", 0);
    }
};

int main() {
    Int n;
    cin >> n;
    vector<LongLong> cmd(static_cast<size_t>(int(n)));
    Int i = 0;
    cout << " ";
    while (int(i) < int(n)) {
        size_t p = static_cast<size_t>(int(i));
        cin >> cmd[p].exi >> cmd[p].neu >> cmd[p].dir;
        ++i;
    }
    Int tar;
    cin >> tar;
    sort(cmd.begin(), cmd.end(), Seg);
    Solve cub;
    cub.dp2(cmd);
    cub.dp1(tar);
    return 0;
}

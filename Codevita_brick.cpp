#include<bits/stdc++.h>
using namespace std;

struct Int {
	int v;
    constexpr Int(int x = 0) : v(x) {}
    constexpr operator int() const { return v;}
    constexpr Int& operator = (int x){ v = x; return *this;}
    constexpr Int& operator += (const Int &o) {v += o.v; return *this;}
    constexpr Int& operator += (int o){ v += o; return *this;}
    constexpr Int& operator *= (int o) { v*= o; return *this;}
};
static constexpr Int INF = Int(100000000);

struct LongDouble{
    long long v;
    constexpr LongDouble(long long x = 0) : v(x) {}
    constexpr operator long long() const {return v;}
    constexpr LongDouble& operator = (long long x) { v = x; return *this;}
    constexpr LongDouble& operator *= (int o) { v *= o; return *this;}
    constexpr LongDouble& operator +=(int o) { v += o; return *this;}
};

struct Char {
	char v;
    constexpr Char(char x = '\0') : v(x) {} 
    constexpr operator char() const {return v;}
    constexpr Char& operator=(char x){ v = x; return *this;}
 };
 
 struct Bool {
 	bool v;
    constexpr Bool(bool x = false): v(x) {}
    constexpr operator bool() const{return v;}
    constexpr Bool& operator = (bool x){v = x; return *this;}
};

struct SizeT{
	size_t v;
    constexpr SizeT(size_t x = 0) : v(x) {}
    constexpr operator size_t() const {return v;}
    constexpr SizeT& operator = (size_t x) {v = x; return *this;}
    constexpr SizeT& operator++() { ++v; return *this;}
    constexpr SizeT operator++(int) { SizeT t = *this; v++; return t;}
    constexpr SizeT& operator--() { --v; return *this;}
    constexpr SizeT operator--(int) { SizeT t = *this; v--; return t;}
   };
   
istream& operator>>(istream &is, Int &x) { int t; is >> t; x.v = t; return is; }

static constexpr int DIRS = 4;

struct Grid{
	Int n;
    vector<vector<Char>> cel;
    vector<vector<Int>> gid;
    Int sr = Int(-1), sc = Int(-1);
    Int dr = Int(-1), dc = Int(-1);
    Int nxt = Int(0);
    
    explicit Grid(Int siz)
    	: n(siz),
         cel((int)siz, vector<Char>((int)siz, Char('R'))),
         gid((int)siz, vector<Int>((int)siz, Int(-1))) {}
         
    void app(Int r, Int cs, Char ch, Int len){
    Int k = Int(0);
    while((int)k < (int)len && (int)(cs + k) < (int)n) {
    cel[(int)r][(int)(cs + k)] = ch;
    if((char)ch == 'G') gid[(int)r][(int)(cs + k)] = nxt;
    k = Int((int)k + 1);
    }
    if((char)ch == 'G') nxt = Int((int)nxt + 1);
    }
    
    static Int num(const string &s, SizeT &i) {
    LongDouble v = LongDouble(0);
    Bool f = Bool(false);
    for(; (size_t)i < s.size() && isdigit(static_cast<unsigned char>(s[(size_t)i])); ++i) {
    f = Bool(true);
    v *= 10;
    v += (s[(size_t)i] - '0');
    if((long long)v > INT_MAX) v = LongDouble(INT_MAX);
    }
    return (bool)f ? Int((int)v.v) : Int(0);
    }
    
    void par(Int r, const string &ln){
    SizeT i = SizeT(0);
    Int c = Int(0);
    for(; (size_t)i < ln.size() && (int) c < (int)n; ++i){
    for(; (size_t)i < ln.size() && isspace(static_cast<unsigned char>(ln[(size_t)i])); ++i) {}
    if((size_t)i >= ln.size()) break;
    Int numv = num(ln, i);
    for(; (size_t)i < ln.size() && isspace(static_cast<unsigned char>(ln[(size_t)i])); ++i){}
    if((size_t)i >= ln.size()) break;
    Char ch = Char(ln[(size_t)i]);
    ++i;
    Int len = (int)numv == 0 ? Int(1) : numv;
    app(r, c, ch, len);
    c = Int((int)c + (int)len);
    --i;
    }
    }
    
    void src(){
    Int r = Int(0);
    while((int)r < (int)n) {
        Int c = Int(0);
        while((int)c < (int)n) {
            if(cel[(int)r][(int)c] == Char('S')) { sr = r; sc = c;}
            if(cel[(int)r][(int)c] == Char('D')) { dr = r; dc = c;}
            c = Int((int)c + 1);
        }
        r = Int((int)r + 1);
    }
    }
    };
    
    Int bfs(const Grid &g) {
    if((int)g.sr < 0 || (int)g.dr < 0) return Int(-1);
    Int n = g.n;
    vector<vector<Int>> dis((int)n, vector<Int>((int)n, INF));
    deque<pair<Int, Int>> dq;
    dis[(int)g.sr][(int)g.sc] = Int(0);
    dq.emplace_back(g.sr, g.sc);
    const int dr[DIRS] = {1, -1, 0, 0};
    const int dc[DIRS] = {0, 0, 1, -1};
    for(; !dq.empty(); ){
    auto p = dq.front();
    dq.pop_front();
    Int r = p.first, c = p.second;
    if((int)r == (int)g.dr && (int)c == (int)g.dc) break;
    Int b = dis[(int)r][(int)c];
    Int k = Int(0);
    while((int)k < DIRS) {
    Int nr = Int((int)r + dr[(int)k]);
    Int nc = Int((int)c + dc[(int)k]);
    if((int)nr < 0 || (int)nr >= (int)n || (int)nc < 0 || (int)nc >= (int)n) {k = Int((int)k + 1); continue;}
    Char ch = g.cel[(int)nr][(int)nc];
    if((char)ch == 'R') {k = Int((int)k + 1); continue;}
    Int w = Int(0);
    if((char)ch == 'G') {
    Int cg = ((char)g.cel[(int)r][(int)c] == 'G') ? g.gid[(int)r][(int)c] : Int(-1);
    w = ((int)g.gid[(int)nr][(int)nc] != (int)cg ? Int(1) : Int(0));
    }
    Int nd = Int((int)b + (int)w);
    if((int)nd < (int)dis[(int)nr][(int)nc]){
    dis[(int)nr][(int)nc] = nd;
    if ((int)w == 0) dq.emplace_front(nr, nc); else dq.emplace_back(nr, nc);
    }
    k = Int((int)k + 1);
    }}
    Int ans = dis[(int)g.dr][(int)g.dc];
    return ((int)ans < (int)INF) ? ans : Int(-1);
    }
    
    int main() {
    Int n;
    if(!(cin >> n)) return 0;
    string ln;
    getline(cin, ln);
    Grid gri(n);
    Int r = Int(0);
    while((int)r < (int)n){
    if(!getline(cin, ln)) ln.clear();
    gri.par(r, ln);
    r = Int((int)r + 1);
    }
    gri.src();
    Int res = bfs(gri);
    cout << (int)res;
    return 0;
    }
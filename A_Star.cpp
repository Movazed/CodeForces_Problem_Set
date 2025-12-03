#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Pt { int r,c; };
#define all(x) (x).begin(), (x).end()

inline int manh(const Pt& a, const Pt& b){ return abs(a.r-b.r)+abs(a.c-b.c); }

inline int enc(int r,int c,int C){ return r*C + c; }

vector<Pt> reconstruct(int goalId, const vector<int>& parent, int R, int C){
    vector<Pt> path;
    for(int v = goalId; v!=-1; v = parent[v]){
        path.push_back({v/C, v%C});
    }
    reverse(all(path));
    return path;
}

vector<Pt> aStarGrid(const vector<vector<int>>& grid, Pt s, Pt t){
    int R = (int)grid.size(), C = (int)grid[0].size();
    const int INF = 1e9;
    vector<int> g(R*C, INF), parent(R*C, -1);
    vector<char> closed(R*C, 0);

    auto inside = [&](int r,int c){ return r>=0 && r<R && c>=0 && c<C && grid[r][c]==0; };

    using Node = tuple<int,int,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int sid = enc(s.r,s.c,C), tid = enc(t.r,t.c,C);
    g[sid] = 0;
    int f0 = manh(s,t);
    pq.emplace(f0, 0, sid);

    const int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};

    while(!pq.empty()){
        auto [fcur, gneg, u] = pq.top(); pq.pop();
        if(closed[u]) continue;
        closed[u] = 1;
        if(u==tid) return reconstruct(tid, parent, R, C); 

        int ur = u / C, uc = u % C;
        for(int k=0;k<4;k++){
            int vr = ur + dr[k], vc = uc + dc[k];
            if(!inside(vr,vc)) continue;
            int v = enc(vr,vc,C);
            if(closed[v]) continue;
            int w = 1; 
            if(g[u] + w < g[v]){
                g[v] = g[u] + w;
                parent[v] = u;
                int h = manh({vr,vc}, t);
                int f = g[v] + h;
                pq.emplace(f, -g[v], v);
            }
        }
    }
    return {};
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int R=5, C=7;
    vector<vector<int>> grid(R, vector<int>(C,0));
    grid[1][2]=grid[2][2]=grid[3][2]=1;
    Pt s{0,0}, t{4,6};
    auto path = aStarGrid(grid, s, t);

    if(path.empty()){ cout<<"No path\n"; return 0; }
    cout<<"Path length: "<<(int)path.size()-1<<"\n";
    for(auto &p: path) cout<<p.r<<" "<<p.c<<"\n";
    return 0;
}
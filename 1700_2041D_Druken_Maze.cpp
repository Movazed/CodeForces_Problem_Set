#include<bits/stdc++.h>

using namespace std;
#define vs vector<string>
#define vvvvi vector<vector<vector<vector<int>>>>
#define vvvvb vector<vector<vector<vector<bool>>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define vi vector<int>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vvi vector<vector<int>>
#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

vs maze;

vvvvi dist;

vvvvb visited;

int n, m;
int startX, startY;
int targetX, targetY;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

const int INF = 0x7fffffff;

void solve(){
    cin >> n >> m;
    maze.resize(n);

    dist = vvvvi(n, vvvi(m , vvi(4, vi(4, INF))
    )
);

    visited = vvvvb(n, vvvb(m, vvb(4, vb(4, false))
    )
);

for(int i = 0; i < n; i++){
    cin >> maze[i];
    for(int j = 0; j < m; j++){
        if(maze[i][j] == 'S'){
            startX = i;
            startY = j;
        } else if(maze[i][j] == 'T'){
            targetX = i;
            targetY = j;
        }
    }
}

    visited[startX][startY][0][0] = true;
    dist[startX][startY][0][0] = 0;

    queue<array<int, 4>> q;

    q.push({startX, startY, 0, 0});
    
    while (!q.empty())
    {
        auto [x, y, dir, stepCount] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
        	int nx = x + dx[i];
        	int ny = y + dy[i];
        	
        	if(nx < 0 || ny < 0 || nx >= n || ny >= m || maze[nx][ny] == '#'){
        		continue;
        	}
        	
        	int newStepCount = (dir == i ? stepCount + 1 : 1);

            if(newStepCount > 3 || visited[nx][ny][i][newStepCount]){
                continue;
            }
        	
            dist[nx][ny][i][newStepCount] = dist[x][y][dir][stepCount] + 1;
            visited[nx][ny][i][newStepCount] = true;
            q.push({nx, ny, i, newStepCount});
        }
    }

    int result = INF;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(visited[targetX][targetY][i][j]){
                result = min(result, dist[targetX][targetY][i][j]);
            }
        }
    }
    cout << (result == INF ? -1 : result) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tcs = 1;

    while (tcs--)
    {
        solve();
    }
    return 0;
}

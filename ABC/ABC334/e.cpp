#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> id(h, vector<int>(w, -1));
    int num = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '#' && id[i][j] == -1){
            queue<pair<int,int>> que;
            que.push({i, j});
            num++;
            id[i][j] = num;
            while(!que.empty()){
                auto [x, y] = que.front(); que.pop();
                rep(d,4){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(id[nx][ny] != -1) continue;
                    if(s[nx][ny] == '.') continue;
                    id[nx][ny] = num;
                    que.push({nx, ny});
                }
            }
        }
    }

    mint ans = 0;
    mint dot_cnt = 0, res = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '.'){
            dot_cnt++;
            set<int> st;
            rep(d,4){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(s[ni][nj] == '#'){
                    st.insert(id[ni][nj]);
                }
            }
            res += num + 1 - (int)st.size();
        }
    }

    mint dot_inv = dot_cnt.inv();
    ans = res * dot_inv;

    cout << ans.val() << endl;
    
    return 0;
}
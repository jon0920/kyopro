#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

const int INF = 1e9;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<vector<int>> cnt(n, vector<int>(m, INF));
    cnt[0][0] = 0;
    deque<pair<int,int>> que;
    que.push_front({0,0});
    while(!que.empty()){
        auto [x, y] = que.front(); que.pop_front();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            int c = 0;
            if(s[nx][ny] == '#') c = 1;

            if(cnt[nx][ny] > cnt[x][y] + c){
                cnt[nx][ny] = cnt[x][y] + c;

                if(c == 0){
                    que.push_front({nx,ny});
                }
                else que.push_back({nx,ny});
            }
        }
    }

    cout << cnt[n - 1][m - 1] << endl;


    return 0;
}
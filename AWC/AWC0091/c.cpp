#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'B'){
                bool ok = false;
                rep(d,4){
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if(x < 0 || x >= h || y < 0 || y >= w) continue;
                    if(s[x][y] == 'R') ok = true;
                }
                if(ok){
                    ans++;
                    s[i][j] = '.';
                }
            }
        }
    }

    rep(qi,q){
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        u--, d--, l--, r--;

        for(int y = l; y <= r; y++){
            if(u != 0 && s[u - 1][y] == 'B'){
                ans++;
                s[u - 1][y] = '.';
            }
            if(d != h - 1 && s[d + 1][y] == 'B'){
                ans++;
                s[d + 1][y] = '.';
            }
        }
        for(int x = u; x <= d; x++){
            if(l != 0 && s[x][l - 1] == 'B'){
                ans++;
                s[x][l - 1] = '.';
            }
            if(r != w - 1 && s[x][r + 1] == 'B'){
                ans++;
                s[x][r + 1] = '.';
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
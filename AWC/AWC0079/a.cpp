#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    bool ok = true;
    rep(i,n){
        rep(j,m){
            if(s[i][j] == '#'){
                int cnt = 0;
                rep(d,4){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(s[nx][ny] == '#') cnt++;
                }
                if(cnt == 0 || cnt == 4) ok = false;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}
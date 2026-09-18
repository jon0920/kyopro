#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    rep(i,n) rep(j,n){
        if(s[i][j] == '#'){
            rep(d,8){
                int x = i, y = j;
                bool ok = true;
                int cnt = 0;
                rep(k,5){
                    x += dx[d];
                    y += dy[d];
                    if(x < 0 || x >= n || y < 0 || y >= n){
                        ok = false;
                        break;
                    }
                    if(s[x][y] == '.') cnt++;
                }
                if(ok && cnt <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}
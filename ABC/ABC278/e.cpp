#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, n, x, y;
    cin >> h >> w >> n >> x >> y;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> cnt(n);
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            a[i][j]--;
            cnt[a[i][j]]++;
        }
    }
    int tot = 0;
    for(int x : cnt) if(x != 0) tot++;

    vector<vector<int>> ans(h - x + 1, vector<int>(w - y + 1));
    rep(i,h - x + 1){
        rep(j,w - y + 1){
            vector<int> tmp = cnt;
            int res = tot;
            for(int ii = i; ii < i + x; ii++){
                for(int jj = j; jj < j + y; jj++){
                    tmp[a[ii][jj]]--;
                    if(tmp[a[ii][jj]] == 0) res--;
                }
            }
            ans[i][j] = res;
        }
    }

    for(auto v : ans){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}
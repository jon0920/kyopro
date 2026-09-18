#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    auto trim = [&](vector<string> v) -> vector<vector<char>> {
        int l = 1000, r = 0, u = 1000, d = 0;
        rep(i,n) rep(j,n){
            if(v[i][j] == '#'){
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }

        vector<vector<char>> res(d - u + 1);
        for(int i = u; i <= d; i++){
            for(int j = l; j <= r; j++) res[i - u].push_back(v[i][j]);
        }

        return res;
    };

    vector<vector<char>> st = trim(s);
    vector<vector<char>> tt = trim(t);

    auto rotate = [](vector<vector<char>> v) -> vector<vector<char>> {
        int x = v.size(), y = v[0].size();
        vector<vector<char>> res(y, vector<char>(x));
        rep(i,x) rep(j,y){
            res[j][x - i - 1] = v[i][j];
        }
        return res;
    };

    rep(i,4){
        if(st.size() != tt.size() || st[0].size() != tt[0].size()){
            tt = rotate(tt);
            continue;
        }

        int x = st.size(), y = st[0].size();
        bool ok = true;
        rep(i,x) rep(j,y){
            if(st[i][j] != tt[i][j]) ok = false;
        }

        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
        tt = rotate(tt);
    }

    cout << "No" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<string>> s(n);
    rep(i,n){
        int k;
        cin >> k;
        s[i].resize(k);
        rep(j,k) cin >> s[i][j];
    }

    auto solve = [&](string x, string y){
        int pos = 0;
        int xsz = x.size(), ysz = y.size();
        rep(i,ysz){
            while(pos < xsz && x[pos] != y[i]) pos++;
            if(pos == xsz) return false;
            pos++;
        }
        return true;
    };

    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int ans = 0;
        for(auto sh : s){
            bool ok = false;
            for(auto b : sh){
                if(solve(b, t)) ok = true;
            }
            if(ok) ans++;
        }
        cout << ans << endl;
    }


    return 0;
}
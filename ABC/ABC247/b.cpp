#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<string>> st(n);
    vector<pair<string,string>> p(n);
    rep(i,n){
        string s, t;
        cin >> s >> t;
        st[i].push_back(s);
        st[i].push_back(t);
        p[i] = {s, t};
    }

    bool ok = true;
    rep(i,n) rep(j,n){
        if(i != j && p[i] == p[j]) ok = false;
    }

    rep(i,n){
        vector<bool> check = {false, false};
        rep(k,2){
            rep(j,n){
                if(i != j){
                    if(st[i][k] == st[j][k]) check[k] = true;
                    if(st[i][k] == st[j][k^1]) check[k] = true;
                }
            }
            if(check[0] && check[1]) ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
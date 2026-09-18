#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    set<string> S;
    vector<pair<string,string>> st(n);
    rep(i,n){
        string s, t;
        cin >> s >> t;
        st[i] = {s,t};
        S.insert(s); S.insert(t);
    }

    map<string,int> mp;
    int cnt = 0;
    for(auto c : S){
        mp[c] = cnt;
        cnt++;
    }
    
    dsu uf(cnt);
    bool ans = true;
    for(auto [s, t] : st){
        int x = mp[s]; int y = mp[t];
        if(uf.same(x, y)) ans = false;
        uf.merge(x, y);
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
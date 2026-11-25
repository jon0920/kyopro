#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;
const int MAX = 2000010;
mint fact[MAX], invfact[MAX];

void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i;
    invfact[MAX - 1] = fact[MAX - 1].inv();
    for(int i = MAX - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);
}

mint nCr(int n, int r){
    if(r < 0 || r > n || n < 0) return 0;
    return fact[n] * invfact[r] * invfact[n - r];
}

int main(){
    
    pre();
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    dsu uf(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    vector<pair<int,int>> cnt(n);
    rep(i,n){
        int root = uf.leader(i);
        if(s[i] == '0') cnt[root].first++;
        else cnt[root].second++;
    }

    mint ans = 1;
    for(auto [x, y] : cnt){
        ans *= nCr(x + y, x);
    }

    cout << ans.val() << endl;
    
    return 0;
}
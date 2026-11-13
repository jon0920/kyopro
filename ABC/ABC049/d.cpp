#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, l;
    cin >> n >> k >> l;
    dsu uf1(n), uf2(n);
    rep(i,k){
        int p, q;
        cin >> p >> q;
        p--, q--;
        uf1.merge(p, q);
    }
    rep(i,l){
        int r, s;
        cin >> r >> s;
        r--, s--;
        uf2.merge(r, s);
    }

    map<pair<int,int>,int> mp;
    rep(i,n){
        int r = uf1.leader(i);
        int t = uf2.leader(i);
        mp[{r, t}]++;
    }

    rep(i,n){
        int r = uf1.leader(i);
        int t = uf2.leader(i);
        cout << mp[{r, t}] << " ";
    }
    cout << endl;
    
    return 0;
}
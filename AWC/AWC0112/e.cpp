#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n; ll k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    fenwick_tree<ll> fw(n + 1);
    ll cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        cnt += fw.sum(0, p[i]);
        fw.add(p[i], 1);
    }

    if(cnt > k) cout << cnt - k << endl;
    else {
        if((k - cnt) % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    
    return 0;
}
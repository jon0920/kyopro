#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k, m;
    cin >> n >> k >> m;
    vector<ll> exp, beg;
    rep(i,n){
        ll h, p;
        cin >> h >> p;
        if(h) exp.push_back(p);
        else beg.push_back(p);
    }

    sort(exp.rbegin(), exp.rend());
    sort(beg.rbegin(), beg.rend());

    if(exp.size() < m || beg.size() < k - m){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i,m) ans += exp[i];
    rep(i,k - m) ans += beg[i];

    cout << ans << endl;
    
    return 0;
}
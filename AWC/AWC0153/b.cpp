#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), p;
    rep(i,n) cin >> x[i];
    p.push_back(-1e18);
    rep(i,m){
        ll y;
        cin >> y;
        p.push_back(y);
    }
    p.push_back(1e18);

    rep(i,n){
        auto it = lower_bound(p.begin(), p.end(), x[i]);
        ll r = *it;
        ll l = *prev(it);
        cout << min(abs(x[i] - r), abs(x[i] - l)) << endl;
    }
    
    return 0;
}
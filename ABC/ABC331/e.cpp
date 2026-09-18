#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, l;
    cin >> n >> m >> l;
    vector<ll> a(n);
    vector<pair<ll,int>> b(m);
    rep(i,n) cin >> a[i];
    rep(i,m){
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(b.rbegin(), b.rend());

    map<int,set<int>> mp;
    rep(i,l){
        int c, d;
        cin >> c >> d;
        c--, d--;
        mp[c].insert(d);
    }

    ll ans = 0;
    rep(i,n){
        if(!mp.count(i)){
            ans = max(ans, a[i] + b[0].first);
        } else {
            rep(j,m){
                if(!mp[i].count(b[j].second)){
                    ans = max(ans, a[i] + b[j].first);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(ab.rbegin(), ab.rend());

    vector<ll> c(m);
    rep(i,m) cin >> c[i];
    sort(c.rbegin(), c.rend());

    priority_queue<ll> pq;
    int cur = 0;
    ll ans = 0;
    for(ll x : c){
        while(cur < n && ab[cur].first >= x){
            pq.push(ab[cur].second);
            cur++;
        }
        if(pq.empty()){
            cout << -1 << endl;
            return 0;
        }
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    sort(p.begin(), p.end());
    vector<pair<ll,ll>> ld(m);
    rep(i,m) cin >> ld[i].first;
    rep(i,m) cin >> ld[i].second;
    sort(ld.begin(), ld.end());

    priority_queue<ll> pq;
    int cur = 0;
    ll ans = 0;
    rep(i,n){
        while(cur < m && ld[cur].first <= p[i]){
            pq.push(ld[cur].second);
            cur++;
        }
        if(!pq.empty()){
            p[i] -= pq.top(); pq.pop();
        }
        ans += p[i];
    }

    cout << ans << endl;
    
    return 0;
}
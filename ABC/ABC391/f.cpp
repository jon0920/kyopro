#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    auto f = [&](ll x, ll y, ll z){
        return x * y + y * z + z * x;
    };

    priority_queue<pair<ll,tuple<int,int,int>>> pq;
    pq.push({f(a[0], b[0], c[0]), {0, 0, 0}});
    set<tuple<int,int,int>> seen;
    seen.insert({0, 0, 0});

    rep(i,k - 1){
        auto [_, ids] = pq.top(); pq.pop();
        auto [ia, ib, ic] = ids;
        if(ia + 1 < n && !seen.count({ia + 1, ib, ic})){
            pq.push({f(a[ia + 1], b[ib], c[ic]), {ia + 1, ib, ic}});
            seen.insert({ia + 1, ib, ic});
        }
        if(ib + 1 < n && !seen.count({ia, ib + 1, ic})){
            pq.push({f(a[ia], b[ib + 1], c[ic]), {ia, ib + 1, ic}});
            seen.insert({ia, ib + 1, ic});
        }
        if(ic + 1 < n && !seen.count({ia, ib, ic + 1})){
            pq.push({f(a[ia], b[ib], c[ic + 1]), {ia, ib, ic + 1}});
            seen.insert({ia, ib, ic + 1});
        }
    }

    cout << pq.top().first << endl;
    
    return 0;
}
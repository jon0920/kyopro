#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    rep(i,n){
        ll s;
        cin >> s;
        pq.push(s);
    }
    vector<tuple<ll,ll,ll>> pir(m);
    rep(i,m){
        ll p, r;
        cin >> p >> r;
        pir[i] = {p, -i, r};
    }
    sort(pir.rbegin(), pir.rend());

    vector<ll> ans(m);
    for(auto [p, i, r] : pir){
        i *= -1;
        if(pq.size() < r){
            cout << -1 << endl;
            return 0;
        }

        ll sum = 0;
        rep(_,r){
            sum += pq.top();
            pq.pop();
        }

        ans[i] = sum;
    }

    for(ll x : ans) cout << x << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, m;
    cin >> n >> k >> m;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        ll c, v;
        cin >> c >> v;
        p[i] = {v, c};
    }
    sort(p.rbegin(), p.rend());

    set<int> st;
    ll ans = 0;
    int cnt = 0;
    priority_queue<pair<ll,ll>> pq;
    rep(i,n){
        auto [v, c] = p[i];
        if(!st.count(c) && st.size() < m){
            ans += v;
            cnt++;
            st.insert(c);
        } else {
            pq.push({v, c});
        }
    }

    while(cnt < k){
        ans += pq.top().first;
        pq.pop();
        cnt++;
    }

    cout << ans << endl;

    
    return 0;
}
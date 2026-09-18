#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> in_out(n);
    rep(i,n){
        ll t, d;
        cin >> t >> d;
        in_out[i] = {t, t + d};
    }
    sort(in_out.begin(), in_out.end());

    ll cur = 0;
    int ans = 0;
    int i = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    while(i < n || !pq.empty()){
        if(pq.empty()){
            cur = max(cur, in_out[i].first);
        }
        while(i < n && in_out[i].first <= cur){
            pq.push(in_out[i].second);
            i++;
        }
        ll r = pq.top(); pq.pop();
        if(r >= cur){
            ans++;
            cur++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
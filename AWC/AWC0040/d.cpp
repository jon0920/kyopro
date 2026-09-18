#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, g, f;
    cin >> n >> g >> f;
    vector<pair<ll,ll>> pr(n);
    rep(i,n) cin >> pr[i].first >> pr[i].second;
    pr.push_back({0, 0});
    pr.push_back({g, 0});
    sort(pr.begin(), pr.end());
    n = pr.size();

    priority_queue<ll> pq;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ll dist = pr[i].first - pr[i - 1].first;
        f -= dist;
        while(!pq.empty() && f < 0){
            ans++;
            f += pq.top();
            pq.pop();
        }
        if(f < 0){
            cout << -1 << endl;
            return 0;
        }
        pq.push(pr[i].second);
    }
    cout << ans << endl;

    return 0;
}
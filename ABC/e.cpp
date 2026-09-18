#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i,n) pq.push(a[i]);
    set<ll> ans;

    while(ans.size() < k){
        ll val = pq.top(); pq.pop();
        if(ans.count(val)) continue;
        ans.insert(val);
        rep(i,n) pq.push(val + a[i]);
    }

    cout << *ans.rbegin() << endl;
    
    return 0;
}
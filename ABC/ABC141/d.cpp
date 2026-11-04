#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    rep(i,n){
        ll a;
        cin >> a;
        pq.push(a);
    }

    while(m--){
        ll x = pq.top(); pq.pop();
        x /= 2;
        pq.push(x);
    }

    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    
    return 0;
}
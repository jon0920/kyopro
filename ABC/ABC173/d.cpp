#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    priority_queue<ll> pq;
    rep(i,n){
        pq.push(a[i]);
        if(i) pq.push(a[i]);
    }

    ll ans = 0;
    rep(i,n - 1){
        ans += pq.top(); pq.pop();
    }
    cout << ans << endl;
    
    return 0;
}
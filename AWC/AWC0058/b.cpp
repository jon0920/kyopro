#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    deque<ll> dq;
    ll sum = 0;
    rep(i,m){
        dq.push_back(h[i]);
        if(h[i] >= k) sum += h[i];
    }
    
    ll ans = sum;
    rep(i,n - m){
        if(dq.front() >= k) sum -= dq.front();
        dq.pop_front();
        if(h[i + m] >= k) sum += h[i + m];
        dq.push_back(h[i + m]);
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
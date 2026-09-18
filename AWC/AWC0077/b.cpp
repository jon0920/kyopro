#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<ll> pq;
    rep(i,n){
        ll sum = a[i];
        pq.push(sum);
        for(int j = 1; j < k; j++){
            if(i + j < n){
                sum += a[i + j];
                pq.push(sum);
            }
        }
    }

    ll ans = 0;
    rep(_,m){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    
    return 0;
}
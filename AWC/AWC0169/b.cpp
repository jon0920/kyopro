#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> w(n);
    rep(i,n) cin >> w[i];
    sort(w.rbegin(), w.rend());
    ll w_sum = 0;
    rep(i,k) w_sum += w[i];

    ll r_sum = 0;
    rep(i,m){
        ll r;
        cin >> r;
        r_sum += r;
    }

    cout << (w_sum >= r_sum ? "Yes" : "No") << endl;
    
    return 0;
}
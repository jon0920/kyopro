#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    vector<ll> dist(n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            ll r = sqrt((long double)d);
            while(r * r < d) r++;
            while(r * r > d) r--;
            dist[i] += r;
            dist[j] += r;
        }
    }

    while(q--){
        int c;
        cin >> c;
        c--;
        cout << dist[c] << endl;
    }
    
    return 0;
}
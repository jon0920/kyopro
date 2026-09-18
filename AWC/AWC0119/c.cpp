#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, a;
    cin >> n >> m >> a;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    int cnt = 0;
    rep(i,n){
        if(h[i] > a){
            if(h[i] > m){
                cout << -1 << endl;
                return 0;
            }
            m /= 2;
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
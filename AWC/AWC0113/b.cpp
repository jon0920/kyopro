#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];

    vector<ll> imos(n + 1);
    vector<ll> a(n);
    ll cur = 0;
    rep(i,n - k + 1){
        cur += imos[i];
        if(cur > t[i]){
            cout << "No" << endl;
            return 0;
        }
        if(cur < t[i]){
            ll d = t[i] - cur;
            imos[i + k] -= d;
            cur += d;
        }
    }
    for(int i = n - k + 1; i < n; i++){
        cur += imos[i];
        if(cur != t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}
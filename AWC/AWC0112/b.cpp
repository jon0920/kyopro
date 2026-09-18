#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    vector<ll> S(n - 1, -1);
    rep(i,m){
        ll p, s;
        cin >> p >> s;
        S[p - 1] = s;
    }

    rep(i,n){
        if(k <= 0){
            cout << "No" << endl;
            return 0;
        }

        k -= d[i];
        if(i != n - 1) k = max(k, S[i]);
    }

    cout << "Yes" << endl;
    
    return 0;
}
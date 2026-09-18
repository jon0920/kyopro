#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, s, t;
    cin >> n >> s >> t;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    sort(d.begin(), d.end());

    rep(i,n){
        if(d[i] <= s) s += d[i];
        else break;
    }

    if(s >= t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> l, r;
    rep(i,n){
        ll x;
        cin >> x;
        if(s[i] == '0') l.push_back(x);
        else r.push_back(x);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll ans = 0;
    for(auto a : l){
        ll ini = a - t * 2, fin = a;
        int left = lower_bound(r.begin(), r.end(), ini) - r.begin();
        int right = lower_bound(r.begin(), r.end(), fin) - r.begin();
        ans += right - left;
    }

    cout << ans << endl;
    return 0;
}
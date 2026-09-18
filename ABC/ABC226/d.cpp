#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    set<pair<ll,ll>> st;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ll r = gcd(dx, dy);
            if(r < 0) r *= -1;
            dx /= r, dy /= r;
            st.insert({dx, dy});
        }
    }
    cout << st.size() << endl;

    return 0;
}
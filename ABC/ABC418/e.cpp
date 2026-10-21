#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    auto count = [&](vector<pair<ll,ll>> &v){
        sort(v.begin(), v.end());
        v.push_back({1e9, 1e9});
        pair<ll,ll> cur = v[0];
        ll res = 0;
        ll c = 0;
        rep(i,v.size()){
            if(cur == v[i]){
                c++;
            } else {
                res += c * (c - 1) / 2;
                c = 1;
                cur = v[i];
            }
        }
        return res;
    };

    vector<pair<ll,ll>> cnt, dup;
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ll sx = x[i] + x[j];
            ll sy = y[i] + y[j];

            ll G = gcd(abs(dx), abs(dy));
            dx /= G;
            dy /= G;
            if(dx < 0 || (dx == 0 && dy < 0)){
                dx *= -1;
                dy *= -1;
            }

            cnt.push_back({dx, dy});
            dup.push_back({sx, sy});
        }
    }

    cout << count(cnt) - count(dup) << endl;
    
    return 0;
}
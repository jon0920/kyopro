#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    vector<ll> l(a.begin(), a.begin() + n / 2);
    vector<ll> r(a.begin() + n / 2, a.end());

    auto gen = [&](vector<ll> &a){
        vector<ll> res;
        int n = a.size();
        for(int bit = 0; bit < (1 << n); bit++){
            ll sum = 0;
            rep(i,n){
                if(bit & (1 << i)) sum += a[i];
            }
            res.push_back(sum);
        }
        return res;
    };

    vector<ll> suml = gen(l);
    vector<ll> sumr = gen(r);
    sort(sumr.begin(), sumr.end());

    ll ans = 0;
    for(auto x : suml){
        ll need = s - x;

        auto l = lower_bound(sumr.begin(), sumr.end(), need);
        auto r = upper_bound(sumr.begin(), sumr.end(), need);

        ans += r - l;
    }
    cout << ans << endl;

    return 0;
}
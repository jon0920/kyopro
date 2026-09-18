#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    auto check = [&](ll x) -> bool {
        ll cnt = 0;
        rep(i,n){
            if(a[i] < x){
                cnt += (x - a[i]) / (i + 1);
                if((x - a[i]) % (i + 1) != 0) cnt++;
                
                if(cnt > k) return false;
            }
        }

        return true;
    };

    ll ok = 1, ng = a[0] + k + 1;
    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll c, d;
        cin >> c >> d;

        auto rt = [](ll x){
            ll res = sqrtl(x);
            while((res + 1) * (res + 1) <= x) res++;
            while(res * res > x) res--;
            return res;
        };
        
        ll ans = 0;
        for(ll p = 10; p <= 10'000'000'000LL; p *= 10){
            ll lo = max(c + 1, p / 10);
            ll hi = min(c + d, p - 1);
            if(lo > hi) continue;

            ll L = c * p + lo;
            ll R = c * p + hi;

            ans += rt(R) - rt(L - 1);
        }
        cout << ans << endl;
    }
    
    return 0;
}
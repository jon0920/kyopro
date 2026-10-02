#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll MAX = 1000010;

ll f(ll a, ll b){
    ll res = (a * a * a) + (a * a * b) + (a * b * b) + (b * b * b);
    return res;
}

int main(){
    
    ll n;
    cin >> n;
    
    ll ans = 8e18;
    for(ll a = 0; a <= MAX; a++){
        ll b_min = -1, b_max = MAX;
        while((b_max - b_min) > 1){
            ll b_mid = (b_max + b_min) / 2;
            if(f(a, b_mid) >= n){
                b_max = b_mid;
            } else {
                b_min = b_mid;
            }
        }
        ans = min(ans, f(a, b_max));
    }

    cout << ans << endl;
    
    return 0;
}
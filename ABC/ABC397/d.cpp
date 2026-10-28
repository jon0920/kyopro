#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll MAX = 1000100;

int main(){
    
    ll n;
    cin >> n;

    for(ll d = 1; d <= MAX; d++){
        if(n % d != 0) continue;
        ll z = n / d;
        
        auto f = [&](ll x){
            return (d * d + 3 * d * x + 3 * x * x);
        };

        ll L = 0, R = 1e9;
        while(R - L > 1){
            ll mid = (R + L) / 2;
            if(f(mid) < z) L = mid;
            else R = mid;
        }

        if(f(R) == z){
            cout << R + d << " " << R << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}
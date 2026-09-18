#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int t;
    cin >> t;
    rep(i,t){
        int n;
        ll h;
        cin >> n >> h;
        ll low = h, high = h;
        ll prev_time = 0;
        bool ok = true;
        rep(j,n){
            ll time, l, u;
            cin >> time >> l >> u;
            ll dt = time - prev_time;
            ll new_low = low - dt, new_high = high + dt;
            
            new_low = max(l, new_low);
            new_high = min(u, new_high);
            if(new_low > new_high) ok = false;

            low = new_low, high = new_high;
            prev_time = time;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
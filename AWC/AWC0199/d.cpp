#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, w, h;
    cin >> n >> w >> h;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    int ans = 0;
    rep(i,n){
        int cnt = 0;
        rep(j,n){
            bool check1 = false, check2 = false;
            if(x[i] <= x[j] && x[i] + w >= x[j]) check1 = true;
            if(y[i] <= y[j] && y[i] + h >= y[j]) check2 = true;
            if(check1 && check2) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    
    return 0;
}
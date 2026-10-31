#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    rep(i,n){
        if(i == 0 || i == n - 1){
            cout << (x[n - 1] - x[0]) / 2 << endl;
        } else {
            //左に進む
            ll t1 = (x[i] - x[0]) / 2;
            ll d1 = (x[i] - x[i - 1]) / 2;
            ll t2 = d1 + (x[n - 1] - d1 - (x[i - 1] + d1)) / 2;
            ll ans_l = max(t1, t2);

            //右に進む
            ll t3 = (x[n - 1] - x[i]) / 2;
            ll d2 = (x[i + 1] - x[i]) / 2;
            ll t4 = d2 + (x[i + 1] - d2 - (x[0] + d2)) / 2;
            ll ans_r = max(t3, t4);

            cout << min(ans_l, ans_r) << endl;
        }
    }
    
    return 0;
}
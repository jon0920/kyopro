#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];

    vector<ll> sum10(n + 1), sum01(n + 1);
    rep(i,n){
        int x = s[i] - '0';
        if(i % 2 == x){
            sum10[i + 1] = sum10[i] + c[i];
            sum01[i + 1] = sum01[i];
        } else {
            sum10[i + 1] = sum10[i];
            sum01[i + 1] = sum01[i] + c[i];
        }
    }

    ll ans = 1e18;
    rep(i,n-1){
        ll res00 = 0, res11 = 0;
        int x1 = s[i] - '0';
        int x2 = s[i + 1] - '0';
        res00 += (x1 == 0 ? 0 : c[i]) + (x2 == 0 ? 0 : c[i + 1]);
        res11 += (x1 == 1 ? 0 : c[i]) + (x2 == 1 ? 0 : c[i + 1]);
        if(i % 2 == 0){
            res00 += sum01[i] - sum01[0];
            res00 += sum10[n] - sum10[i + 2];
            res11 += sum10[i] - sum10[0];
            res11 += sum01[n] - sum01[i + 2];
        } else {
            res00 += sum10[i] - sum10[0];
            res00 += sum01[n] - sum01[i + 2];
            res11 += sum01[i] - sum01[0];
            res11 += sum10[n] - sum10[i + 2];
        }
        ans = min(ans, min(res00, res11));
    }

    cout << ans << endl;
    
    return 0;
}
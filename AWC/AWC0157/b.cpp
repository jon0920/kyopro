#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll mn = 0;
    ll ans = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ans += a - b;
        mn = min(mn, ans);
    }

    cout << max(0LL, mn * -1) << endl;
    
    return 0;
}
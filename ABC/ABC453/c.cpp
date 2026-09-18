#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        ll pos = 1;
        int cnt = 0;
        rep(i,n){
            ll npos = pos;
            if(bit & (1 << i)){
                npos += l[i];
                if(pos <= 0 && npos > 0) cnt++;
            } else {
                npos -= l[i];
                if(pos > 0 && npos <= 0) cnt++;
            }
            pos = npos;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
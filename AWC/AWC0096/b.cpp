#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, s, k;
    cin >> n >> s >> k;
    ll cnt = 0;
    rep(i,n - 1){
        ll e;
        cin >> e;
        if(e > s){
            cnt += e - s;
            s = e * 2;
        } else s += e;
    }

    if(cnt > k) cout << -1 << endl;
    else cout << cnt << endl;
    
    return 0;
}
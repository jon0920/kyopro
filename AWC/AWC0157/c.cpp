#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, s;
    cin >> n >> m >> s;
    ll pos = s;
    ll cnt = 0;
    rep(i,n){
        char c; ll a;
        cin >> c >> a;
        if(c == 'L') pos *= -1;
        pos += a;
        cnt += max(0LL, (c == 'L' ? pos + m : pos) - 1) / m;
        pos = (pos + 2 * m) % (2 * m);
        if(pos > m) pos = 2 * m - pos;
    }

    cout << pos << " " << cnt << endl;
    
    return 0;
}
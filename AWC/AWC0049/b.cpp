#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll s, t, k;
    cin >> s >> t >> k;

    bool ok = false;
    int cnt = 0;
    if(s == t) ok = true;
    
    while(s < t && cnt < k){
        s *= 2;
        cnt++;
        if(s == t){
            ok = true;
            break;
        }
    }

    if(ok) cout << cnt << endl;
    else cout << -1 << endl;

    return 0;
}
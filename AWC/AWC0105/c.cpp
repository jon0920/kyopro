#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i,n - 1){
        int x_l = 0, x_r = 0;
        rep(j,n){
            if(j <= i) x_l ^= s[j];
            else x_r ^= s[j];
        }

        vector<int> a(n);
        rep(j,n){
            if(j <= i) a[j] = s[j] ^ x_r;
            else a[j] = s[j] ^ x_l;
        }

        bool ok = true;
        int cur = 127;
        rep(j,n){
            int l = 97 - a[j], r = 122 - a[j];
            if(r < 0){
                ok = false;
                break;
            }
            cur = min(cur, r);
            if(cur < l){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }

    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    while(q--){
        int type; cin >> type;
        if(type == 1){
            ll i, A, B;
            cin >> i >> A >> B;
            i--;
            a[i] = A;
            b[i] = B;
        } else {
            ll d;
            cin >> d;
            ll rem = d, res = -1, mn = d;
            rep(i,n){
                rem += a[i] - b[i];
                if(rem <= 0){
                    res = i + 1;
                    break;
                }
                mn = min(mn, rem);
            }
            if(res >= 0){
                cout << res << endl;
                continue;
            }
            if(rem >= d){
                cout << -1 << endl;
                continue;
            }

            ll dist = d - rem;
            ll cycles = (mn + dist - 1) / dist;
            res = cycles * n;
            rem = d - cycles * dist;
            int i = 0;
            while(++i){
                rem += a[(i - 1) % n] - b[(i - 1) % n];
                if(rem <= 0){
                    cout << res + i << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
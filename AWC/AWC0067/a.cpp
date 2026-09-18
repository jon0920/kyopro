#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> s(n);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            ll v;
            cin >> a >> b >> v;
            a--, b--;
            s[a] -= v;
            s[b] += v;
        } else if(type == 2){
            int x, l, r;
            cin >> x >> l >> r;
            x--, l--;
            int cnt = 0;
            for(int i = l; i < r; i++){
                if(s[i] > s[x]) cnt++;
            }
            cout << cnt << endl;
        } else {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            l--;
            for(int i = l; i < r; i++) s[i] += v;
        }
    }

    return 0;
}
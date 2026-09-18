#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint;

int main(){
    
    int n, q, m;
    cin >> n >> q >> m;
    mint::set_mod(m);

    vector<mint> P(n);
    mint prod = 1;
    int zero_cnt = 0;
    rep(i,n){
        int p;
        cin >> p;
        P[i] = p;
        if(p == 0){
            zero_cnt++;
        } else {
            prod *= p;
        }
    }

    while(q--){
        int x, v;
        cin >> x >> v;
        x--;
        mint base;
        if(P[x].val() == 0){
            base = (zero_cnt == 1 ? prod : 0);
        } else {
            base = (zero_cnt > 0 ? 0 : prod / P[x]);
        }
        mint ans = base * v;
        cout << ans.val() << endl;
    }
    
    return 0;
}
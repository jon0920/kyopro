#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> w(n), c(m);
    ll sum_w = 0, sum_c = 0;
    rep(i,n) cin >> w[i], sum_w += w[i];
    rep(i,m) cin >> c[i], sum_c += c[i];

    if(sum_w > sum_c){
        cout << "No" << endl;
        return 0; 
    }

    sort(c.rbegin(), c.rend());
    if(m > n){
        c.resize(n);
        m = n;
    }

    vector<int> dp_k(1 << n, m + 1);
    vector<ll> dp_rem(1 << n, -1);
    dp_k[0] = 0;
    dp_rem[0] = c[0];

    for(int mask = 0; mask < (1 << n); mask++){
        int k = dp_k[mask];
        ll rem = dp_rem[mask];

        if(k >= m) continue;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))){
                int next_mask = mask | (1 << i);
                ll wi = w[i];

                int nk;
                ll nrem;

                if(wi <= rem){
                    nk = k;
                    nrem = rem - wi;
                }
                else if(k + 1 < m && wi <= c[k + 1]){
                    nk = k + 1;
                    nrem = c[k + 1] - wi;
                }
                else{
                    continue;
                }

                if(nk < dp_k[next_mask]){
                    dp_k[next_mask] = nk;
                    dp_rem[next_mask] = nrem;
                }
                else if(nk == dp_k[next_mask]  && nrem > dp_rem[next_mask]){
                    dp_rem[next_mask] = nrem;
                }
            }
        }
    }

    if(dp_k[(1 << n) - 1] < m) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, K;
    cin >> n >> K;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    if(K == 1){
        cout << "Infinity" << endl;
        return 0;
    }

    int ans = 0;
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            int cnt = 0;
            bool first = true;
            
            rep(k,n){
                if(i == k || j == k) continue;

                ll dx_ij = x[j] - x[i];
                ll dy_ij = y[j] - y[i];
                ll dx_ik = x[k] - x[i];
                ll dy_ik = y[k] - y[i];

                ll cross = dx_ij * dy_ik - dy_ij * dx_ik;
                if(cross == 0){
                    cnt++;
                    if(k < i || (i < k && k < j)) first = false;
                }
            }
            if(first && cnt + 2 >= K) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> t(n), p(n);
    rep(i,n) cin >> t[i] >> p[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        int cost = 0;
        int sum = 0;
        rep(i,n){
            if(1 & (bit >> i)){
                cost += t[i];
                sum += p[i];
            }
        }
        if(cost <= m) ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}
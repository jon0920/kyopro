#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> f(n), b(n);
    rep(i,n) cin >> f[i] >> b[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        int sum = 0, cnt = 0;
        rep(i,n){
            if(bit & (1 << i)){
                cnt++;
                sum += b[i];
            } else sum += f[i];
        }
        if(cnt == k) ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}
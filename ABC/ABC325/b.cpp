#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    rep(i,n) cin >> w[i] >> x[i];

    int ans = 0;
    rep(i,24){
        int cnt = 0;
        rep(j,n){
            int t = (x[j] + i) % 24;
            if(t >= 9 && t < 18) cnt += w[j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    
    return 0;
}
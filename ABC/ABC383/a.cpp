#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> t(n+1), v(n);
    t[0] = 0;
    rep(i,n) cin >> t[i+1] >> v[i];

    int ans = 0;
    int dic;
    rep(i,n){
        dic = (t[i+1] - t[i]);
        ans = max(ans - dic, 0);
        ans += v[i];
    }

    cout << ans << endl;

    
    return 0;
}
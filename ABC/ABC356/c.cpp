#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(m);
    vector<int> c(m);
    vector<char> r(m);
    rep(i,m){
        cin >> c[i];
        a[i].resize(c[i]);
        rep(j,c[i]){
            cin >> a[i][j];
            a[i][j]--;
        }
        cin >> r[i];
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool ok = true;
        rep(i,m){
            int cnt = 0;
            rep(j,c[i]){
                if((1 << a[i][j]) & bit) cnt++;
            }
            if((cnt < k && r[i] == 'o') || (cnt >= k && r[i] == 'x')) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
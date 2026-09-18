#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    vector<bool> ok(n + 1);
    ok[0] = true; ok[n] = true;

    rep(i,n){
        if(l[i] == 1) break;
        else ok[i + 1] = true;
    }
    for(int i = n - 1; i >= 0; i--){
        if(l[i] == 1) break;
        else ok[i] = true;
    }
    int ans = 0;
    for(auto a : ok) if(!a) ans++;
    cout << ans << endl;
    
    return 0;
}
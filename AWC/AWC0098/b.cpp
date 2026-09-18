#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    sort(t.begin(), t.end());

    for(auto x : s){
        auto it = upper_bound(t.begin(), t.end(), x);
        int ans = it - t.begin();
        cout << ans << endl;
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> r(n), s(m);
    rep(i,n) cin >> r[i];
    rep(i,m) cin >> s[i];
    int mn = *min_element(s.begin(), s.end());

    int ans = 0;
    rep(i,n){
        if(r[i] <= mn) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n), r(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> r[i];
    sort(s.begin(), s.end());
    sort(r.begin(), r.end());
    rep(i,k) s.pop_back();
    n = s.size();

    int ans = 0;
    int x = 0, y = 0;
    while(x < n && y < m){
        if(s[x] >= r[y]){
            ans++;
            x++, y++;
        } else {
            x++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int ans = 1e9;
    rep(i,n - m + 1){
        string sub = s.substr(i, m);
        int cnt = 0;
        rep(j,m){
            if(sub[j] != t[j]) cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    
    return 0;
}
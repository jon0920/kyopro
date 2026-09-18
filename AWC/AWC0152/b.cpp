#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q, m;
    cin >> n >> q >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int p; char c;
            cin >> p >> c;
            p--;
            s[p] = c;
        } else {
            vector<bool> seen(n, false);
            int cur = 0;
            ll res = 0;
            for(char c : s){
                if(c == 'R') cur = min(n - 1, cur + 1);
                else if(c == 'L') cur = max(0, cur - 1);
                else if(c == 'B') cur = 0;
                else {
                    if(!seen[cur]){
                        res += a[cur];
                        seen[cur] = true;
                    }
                }
            }
            cout << res << endl;
        }
    }
    
    return 0;
}
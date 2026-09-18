#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> c(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        c[p[i]].push_back(i);
    }

    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];

    vector<ll> s(n + 1);

    for(int i = n; i >= 1; i--){
        s[i] += w[i];
        s[p[i]] += s[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(c[i].size() >= 2){
            ll min_s = -1, max_s = -1;
            for(int x : c[i]){
                ll val = s[x];
                if(min_s == -1 || val < min_s) min_s = val;
                if(max_s == -1 || val > max_s) max_s = val; 
            }
            ans = max(ans, max_s - min_s);
        }
    }
    cout << ans << endl;

    return 0;
}
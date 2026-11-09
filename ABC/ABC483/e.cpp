#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    map<string, ll> cnt;
    ll e0 = 0;
    rep(i,n){
        cin >> s[i];
        e0 += cnt[s[i]];
        cnt[s[i]]++;
    }

    ll e1 = 0;
    rep(i,m){
        cnt.clear();
        rep(j,n){
            string t;
            rep(x,m){
                if(x != i) t += s[j][x];
            }
            e1 += cnt[t];
            cnt[t]++;
        }
    }

    ll e2 = 0;
    rep(i,m){
        for(int j = i + 1; j < m; j++){
            cnt.clear();
            rep(k,n){
                string t;
                rep(x,m){
                    if(x != i && x != j) t += s[k][x];
                }
                e2 += cnt[t];
                cnt[t]++;
            }
        }
    }

    ll ans0 = e0;
    ll ans1 = e1 - m * ans0;
    ll ans2 = e2 - (m * (m - 1) / 2) * ans0 - (m - 1) * ans1;

    cout << ans0 + ans1 + ans2 << endl;
        
    return 0;
}
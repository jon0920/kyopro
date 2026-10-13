#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<pair<int,int>>> prime_fact(n);
        map<int,pair<int,int>> mp;
        rep(i,n){
            int a;
            cin >> a;
            for(int p = 2; p * p <= a; p++){
                if(a % p != 0) continue;
                int exp = 0;
                while(a % p == 0){
                    exp++;
                    a /= p;
                }
                prime_fact[i].push_back({p, exp});
                if(!mp.count(p)){
                    mp[p] = {exp, 0};
                } else {
                    if(exp > mp[p].first){
                        mp[p].second = mp[p].first;
                        mp[p].first = exp;
                    } else if(exp > mp[p].second) {
                        mp[p].second = exp;
                    }
                }
            }
            if(a > 1){
                prime_fact[i].push_back({a, 1});
                auto &[mx, mx2] = mp[a];
                if(mx == 0) mx = 1;
                else mx2 = max(mx2, 1);
            }
        }

        mint base = 1;
        for(auto [k, v] : mp){
            base *= mint(k).pow(v.first);
        }

        rep(i,n){
            mint res = base;
            for(auto [x, y] : prime_fact[i]){
                if(y == mp[x].first){
                    res /= mint(x).pow(mp[x].first - mp[x].second);
                }
            }
            cout << res.val() << " ";
        }
        cout << endl;
    }
    
    return 0;
}
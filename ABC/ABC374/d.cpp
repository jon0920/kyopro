#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

long double dist(pair<int,int> l, pair<int,int> r){
    ll v = 0;
    auto [la, lb] = l;
    auto [ra, rb] = r;
    v += (la - ra) * (la - ra);
    v += (lb - rb) * (lb - rb);
    return sqrtl((long double) v);
}


int main() {
    
    int n, s, t;
    cin >> n >> s >> t;
    vector<pair<int,int>> init(n), fin(n);
    rep(i,n){
        cin >> init[i].first >> init[i].second >> fin[i].first >> fin[i].second;
    }

    long double ans = 8e18;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    do{
        for(int i = 0; i < (1 << n); i++){
            long double cres = 0.0;
            pair<int,int> cur = {0, 0};
            for(int j = 0; j < n; j++){
                int el = p[j];
                if(i & (1 << j)){
                    cres += (dist(cur, init[el]) / (long double) s);
                    cres += (dist(init[el], fin[el]) / (long double) t);
                    cur = fin[el];
                }
                else{
                    cres += (dist(cur, fin[el]) / (long double) s);
                    cres += (dist(fin[el], init[el]) / (long double) t);
                    cur = init[el];
                }
            }
            ans = min(ans, cres);
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}
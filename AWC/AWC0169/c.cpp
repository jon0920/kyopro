#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k), b(k);
    rep(i,k) cin >> a[i] >> b[i];

    while(q--){
        int x, p, v;
        cin >> x >> p >> v;
        p--;
        if(x == 1){
            a[p] = v;
        } else {
            b[p] = v;
        }

        vector<int> c = a;
        vector<int> d = b;
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        map<int,int> mp;
        for(auto &m : c) mp[m] = 0;
        for(auto &m : d) mp[m] = 0;
        int num = 0;
        for(auto &[mk, mv] :  mp){
            mv = num;
            num++;
        }

        dsu uf(mp.size());
        rep(i,k){
            c[i] = mp[c[i]];
            d[i] = mp[d[i]];
            uf.merge(c[i], d[i]);
        }

        rep(i,k){
            cout << (uf.size(c[i]) & 1) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
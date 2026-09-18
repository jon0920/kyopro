#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

vector<vector<ll>> bit_btute_force(vector<ll> &v){
    int n = v.size();
    vector<vector<ll>> res(n + 1);
    for(int bit = 0; bit < (1 << n); bit++){
        ll cnt = 0, sum = 0;
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1){
                cnt++;
                sum += v[i];
            }
        }   
        res[cnt].push_back(sum);
    }
    return res;
};

ll solve(vector<ll> &v1, vector<ll> &v2, ll x){
    ll res = 0; int j = 0;
    sort(v1.rbegin(), v1.rend());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < (int)v1.size(); i++){
        while(j < (int)v2.size() && v1[i] + v2[j] < x) j++;
        res += (int)v2.size() - j;
    }
    return res;
};

int main(){
    
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n), l, r;
    rep(i,n){
        cin >> a[i];
        if(i % 2 == 0) l.push_back(a[i]);
        else r.push_back(a[i]);
    }

    vector<vector<ll>> L = bit_btute_force(l);
    vector<vector<ll>> R = bit_btute_force(r);

    ll ans = 0;
    for(int i = 0; i < (int)L.size(); i++){
        int j = k - i;
        if(j < 0 || j >= (int)R.size()) continue;
        ans += solve(L[i], R[j], x);
    }

    cout << ans << endl;
    
    return 0;
}
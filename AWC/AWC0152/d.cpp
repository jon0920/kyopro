#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, s;
    cin >> n >> s;
    int n1 = (n + 1) / 2;
    int n2 = n - n1;
    vector<ll> p, q;
    rep(i,n){
        ll x;
        cin >> x;
        if(i < n1) p.push_back(x);
        else q.push_back(x);
    }

    map<ll,ll> p_mp, q_mp;
    for(int bit = 0; bit < (1 << n1); bit++){
        ll sum = 0;
        rep(i,n1){
            if((bit >> i) & 1){
                sum += p[i];
                if(sum > s) break;
            }
        }
        if(sum <= s) p_mp[sum]++;
    }
    for(int bit = 0; bit < (1 << n2); bit++){
        ll sum = 0;
        rep(i,n2){
            if((bit >> i) & 1){
                sum += q[i];
                if(sum > s) break;
            }
        }
        if(sum <= s) q_mp[sum]++;
    }

    int cnt = 0;
    for(auto [k, v] : p_mp){
        if(q_mp.count(s - k)){
            cnt += v * q_mp[s - k];
            if(cnt >= 2){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << (cnt == 0 ? "NO" : "ALMOST") << endl;
    
    return 0;
}
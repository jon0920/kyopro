#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    map<ll,ll> mp;
    ll ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
        ans += a;
    }

    map<ll,bool> check;
    for(auto [k, _] : mp) check[k] = false;

    ll mx = 0;
    for(auto [k, v] : mp){
        if(!check[k]){
            ll sum = 0;
            queue<ll> que;
            que.push(k);
            check[k] = true;
            sum += k * v;
            while(!que.empty()){
                ll now = que.front(); que.pop();
                ll pre = (now - 1 + m) % m;
                ll nxt = (now + 1) % m;
                if(check.count(pre) && !check[pre]){
                    check[pre] = true;
                    sum += pre * mp[pre];
                    que.push(pre);
                }
                if(check.count(nxt) && !check[nxt]){
                    check[nxt] = true;
                    sum += nxt * mp[nxt];
                    que.push(nxt);
                }
            }
            mx = max(mx, sum);
        }
    }

    cout << ans - mx << endl;
    
    return 0;
}
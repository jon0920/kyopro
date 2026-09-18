#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main(){
    int q;
    cin >> q;
    queue<pair<ll, ll>> que;
    for(int i = q; i > 0; i--){
        int type;
        cin >> type;
        if(type == 1){
            int c, x;
            cin >> c >> x;
            que.emplace(c, x);
        }
        else{
            int k;
            cin >> k;
            ll ans = 0;
            while(!que.empty() && que.front().first <= k){
                ans += que.front().first * que.front().second;
                k -= que.front().first;
                que.pop();
            }
            if(k != 0){
                que.front().first -= k;
                ans += k * que.front().second;
            }
            cout << ans << endl;
        }
    }
}
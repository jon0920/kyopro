#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    ll offset = 0;
    queue<ll> que;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            que.push(offset);
        }
        else if(type == 2){
            ll t;
            cin >> t;
            offset += t;
        }
        else{
            ll h;
            cin >> h;
            ll harvest = offset - h;
            int cnt = 0;
            while(!que.empty() && que.front() <= harvest){
                cnt++;
                que.pop();
            }
            cout << cnt << endl;
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    rep(ti,t){
        int n, d;
        cin >> n >> d;
        queue<pair<int,int>> que;
        vector<int> a(n), b(n);
        rep(i,n) cin >> a[i];
        rep(i,n) cin >> b[i];
        rep(i,n){
            que.push({a[i], i});
            while(b[i] > 0){
                if(que.front().first >= b[i]){
                    que.front().first -= b[i];
                    b[i] = 0;
                }
                else{
                    b[i] -= que.front().first;
                    que.pop();
                }
            }
            while(i - que.front().second >= d) que.pop();
        }
        ll ans = 0;
        while(!que.empty()){
            ans += que.front().first;
            que.pop();
        }
        cout << ans << endl;
    }

    return 0;
}
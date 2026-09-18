#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> dv(n);
    rep(i,n) cin >> dv[i].first >> dv[i].second;
    sort(dv.begin(), dv.end());
    
    vector<int> l(m);
    rep(i,m) cin >> l[i];
    sort(l.begin(), l.end());

    priority_queue<int> pq;
    int cur = 0;
    ll ans = 0;
    for(int x : l){
        while(cur < n && dv[cur].first <= x){
            pq.push(dv[cur].second);
            cur++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
    
    return 0;
}
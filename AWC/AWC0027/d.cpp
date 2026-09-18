#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> s(n);
    rep(i,n) cin >> s[i].first >> s[i].second;
    sort(s.begin(), s.end());
    vector<int> p(m);
    rep(i,m) cin >> p[i];
    sort(p.begin(), p.end());

    int pos = 0;
    priority_queue<int> q;
    ll ans = 0;
    rep(i,m){
        while(pos < n && s[pos].first <= p[i]){
            q.push(s[pos].second);
            pos++;
        }

        if(q.size()){
            ans += q.top();
            q.pop();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
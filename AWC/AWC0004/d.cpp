#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> p(m);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        p[i] = {l, r};
    }
    sort(p.begin(), p.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int id = 0, cnt = 0;
    for(int j = 1; j <= n; j++){
        while(id < m && p[id].first <= j){
            pq.push(p[id].second);
            id++;
        }

        if(!pq.empty()){
            int v = pq.top(); pq.pop();
            if(v < j){
                cout << "No" << endl;
                return 0;
            }
            cnt++;
        }
        if(cnt == m) break;
    }

    if(cnt == m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
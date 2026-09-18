#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<pair<int,int>> pq;
    rep(i,m){
        int b;
        cin >> b;
        pq.push({b, i});
    }

    vector<int> ans(m, -1);
    rep(i,n){
        while(!pq.empty()){
            auto [b, id] = pq.top();
            if(b >= a[i]){
                ans[id] = i + 1;
                pq.pop();
            } else {
                break;
            }
        }
    }

    for(auto x : ans) cout << x << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(n);
    vector<int> cnt(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[a].push_back(b);
        cnt[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i,n){
        if(cnt[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int i = pq.top(); pq.pop();
        cout << i + 1 << ' ';
        for(auto &x : ab[i]){
            cnt[x]--;
            if(cnt[x] == 0) pq.push(x);
        }
    }

    cout << endl;

    return 0;
}
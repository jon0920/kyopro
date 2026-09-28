#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll x, y, pow;
};

int main(){
    
    int n;
    cin >> n;

    vector<S> cand(n);
    rep(i,n){
        ll x, y, p;
        cin >> x >> y >> p;
        cand[i] = {x, y, p};
    }

    auto solve = [&](ll mid){
        vector<vector<int>> G(n);
        rep(i,n){
            rep(j,n){
                if(i != j){
                    ll d = abs(cand[i].x - cand[j].x) + abs(cand[i].y - cand[j].y);
                    if(d <= cand[i].pow * mid) G[i].push_back(j);
                }
            }
        }

        rep(i,n){
            vector<bool> seen(n, false);
            seen[i] = true;
            queue<int> que;
            que.push(i);
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(int nv : G[v]){
                    if(!seen[nv]){
                        que.push(nv);
                        seen[nv] = true;
                    }
                }
            }
            bool ok = true;
            rep(i,n){
                if(!seen[i]) ok = false;
            }
            if(ok) return true;
        }
        return false;
    };

    ll ok = 5e9, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}
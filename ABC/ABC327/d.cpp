#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<pair<int,int>> ab(m);
    rep(i,m) cin >> ab[i].first, ab[i].first--;
    rep(i,m) cin >> ab[i].second, ab[i].second--;
    for(auto [a, b] : ab){
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(n, -1);
    queue<int> que;
    for(auto [a, b] : ab){
        if(color[a] == -1 && color[b] == -1){
            color[a] = 0, color[b] = 1;
            que.push(a);
            que.push(b);
        }
        else if(color[a] == -1 || color[b] == -1){
            if(color[a] == -1){
                color[b] = color[a] ^ 1;
                que.push(b);
            } else {
                color[a] = color[b] ^ 1;
                que.push(a);
            }
        }
        else{
            if(color[a] == color[b]){
                cout << "No" << endl;
                return 0;
            }
        }
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto nv : G[v]){
                if(color[nv] != -1){
                    if(color[v] == color[nv]){
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    color[nv] = color[v] ^ 1;
                    que.push(nv);
                }
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}
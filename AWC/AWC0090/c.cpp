#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    ll L, R, P, Q;
};

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n);
    rep(i,n){
        cin >> nodes[i].L >> nodes[i].R >> nodes[i].P >> nodes[i].Q;
    }

    bool ok = true;
    vector<vector<int>> child(n, vector<int>(2, 0));
    vector<int> deg(n);
    rep(i,m){
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        if(child[u][b] != 0) ok = false;
        child[u][b] = v;
        deg[v]++;
    }

    rep(i,n){
        if(i == 0){
            if(deg[i] != 0) ok = false;
        } else {
            if(deg[i] != 1) ok = false;
        }
    }

    if(!ok){
        cout << "NO" << endl;
        return 0;
    }

    queue<int> que;
    vector<bool> seen(n);
    que.push(0);
    seen[0] = true;

    while(!que.empty()){
        int v = que.front(); que.pop();
        int c1 = child[v][0];
        int c2 = child[v][1];

        if(c1 != 0){
            if(nodes[v].L >= nodes[c1].L || nodes[v].R <= nodes[c1].R) ok = false;
            if(nodes[v].Q != nodes[c1].P) ok = false;
            if(!seen[c1]){
                seen[c1] = true;
                que.push(c1);
            }
        }
        if(c2 != 0){
            if(nodes[v].L >= nodes[c2].L || nodes[v].R <= nodes[c2].R) ok = false;
            if(nodes[v].Q != nodes[c2].P) ok = false;
            if(!seen[c2]){
                seen[c2] = true;
                que.push(c2);
            }
        }
        if(c1 != 0 && c2 != 0){
            if(nodes[c1].R >= nodes[c2].L) ok = false;
        }
    }
    rep(i,n) if(!seen[i]) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
    
    return 0;
}
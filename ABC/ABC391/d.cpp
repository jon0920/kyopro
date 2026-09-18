#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int x, y, id;
};

const int INF = 1e9;

int main(){

    int n, w;
    cin >> n >> w;
    vector<S> pos(n);
    vector<vector<pair<int,int>>> vert(w);
    rep(i,n){
        int x, y;
        cin >> x >> y;
        x--, y--;
        pos[i] = {x, y, i};
        vert[x].push_back({y, i});
    }
    
    int min_stack = INF;
    for(auto &v : vert){
        sort(v.begin(), v.end());
        min_stack = min(min_stack, (int)v.size());
    }
    
    vector<int> time(n, -INF);
    vector<int> st(n ,-1);
    rep(i,min_stack){
        rep(j,w){
            auto [y, id] = vert[j][i];
            st[id] = i;
            if(i == 0) time[i] = max(time[i], y);
            else time[i] = max(time[i], max(time[i - 1] + 1, y));
        }
    }
    for(int i = min_stack; i < n; i++) time[i] = INF;


    int q;
    cin >> q;
    while(q--){
        int t, a;
        cin >> t >> a;
        a--;
        if(st[a] == -1){
            cout << "Yes" << endl;
            continue;
        }
        
        if(time[st[a]] < t) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
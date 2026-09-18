#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m, x;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    cin >> x;

    vector<bool> can_reached(x + 1, false);
    can_reached[0] = true;
    queue<int> que;
    que.push(0);

    auto valid = [&](int c){
        return (!binary_search(b.begin(),b.end(), c) && c <= x);
    };
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(auto p : a){
            if(valid(now + p) && !can_reached[now + p]){
                can_reached[now + p] = true;
                que.push(now + p);
            }
        }
    }
    if(can_reached[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
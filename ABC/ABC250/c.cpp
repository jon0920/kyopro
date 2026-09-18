#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    vector<int> pos(n), val(n);
    iota(pos.begin(), pos.end(), 0);
    iota(val.begin(), val.end(), 0);
    
    while(q--){
        int x;
        cin >> x;
        x--;
        int p0 = pos[x];
        int p1 = p0;
        if(p0 == n - 1) p1--;
        else p1++;
        int v0 = val[p0];
        int v1 = val[p1];
        swap(val[p0], val[p1]);
        swap(pos[v0], pos[v1]);
    }

    rep(i,n){
        if(i) cout << ' ';
        cout << val[i] + 1;
    }
    cout << endl;
    
    return 0;
}
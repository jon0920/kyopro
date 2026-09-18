#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;
            a--, b--;
            v[b] += v[a];
            v[a] = 0;
        }
        else{
            int c;
            cin >> c;
            c--;
            cout << v[c] << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> w(m - 1);
    int mx = 0;
    rep(i,m - 1){
        int W;
        cin >> W;
        if(mx < W) mx = W;
        w[i] = mx;
    }
    
    rep(i,n){
        int b;
        cin >> b;
        int it = upper_bound(w.begin(), w.end(), b) - w.begin();
        cout << it + 1 << endl;
    }

    return 0;
}
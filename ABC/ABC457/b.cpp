#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(i,n){
        int l;
        cin >> l;
        a[i].resize(l);
        rep(j,l) cin >> a[i][j];
    }

    int x, y;
    cin >> x >> y;
    cout << a[x - 1][y - 1] << endl;

    return 0;
}
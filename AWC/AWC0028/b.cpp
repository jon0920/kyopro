#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> t(n);
    bool ok = false;
    rep(i,n){
        cin >> t[i];
        if(t[i] >= l && t[i] <= r) ok = true;
    }

    if(!ok){
        cout << 0 << endl;
        return 0;
    }

    int fin = 0;
    int ans = 0;
    for(int ini = 0; ini < n; ini++){
        fin = ini;
        while(fin < n && t[fin] >= l && t[fin] <= r) fin++;
        ans = max(ans, fin - ini);
        ini = fin;
    }

    cout << ans << endl;

    return 0;
}
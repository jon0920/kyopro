#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<bool> t(n);
    rep(i,n){
        int x;
        cin >> x;
        t[x - 1] = true;
    }

    int ans = 0;
    rep(i,n) if(!t[i]) ans++;
    cout << ans << endl;
    
    return 0;
}
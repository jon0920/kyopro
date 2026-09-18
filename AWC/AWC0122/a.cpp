#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<bool> cand(n);
    cand[0] = true;

    rep(i,m){
        int a, b;
        cin >> a >> b;
        if(cand[a]) cand[b] = true;
    }

    int ans = 0;
    rep(i,n) if(cand[i]) ans++;
    cout << ans << endl;
    
    return 0;
}
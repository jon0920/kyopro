#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i], p[i]--;
    
    vector<bool> seen(n);
    seen[0] = true;
    int id = 0;
    while(!seen[p[id]]){
        seen[p[id]] = true;
        id = p[id];
    }

    int ans = 0;
    rep(i,n) ans += seen[i];
    cout << ans << endl;
    
    return 0;
}
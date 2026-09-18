#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    int ans = 0;
    int mx = 0;
    rep(i,m){
        int p;
        cin >> p;
        cnt[p]++;
        mx = max(mx, cnt[p]);
        if(p == 2){
            if(mx > cnt[p]) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,n){
        cin >> c[i];
        c[i]--;
    }

    vector<int> cnt(7);
    ll ans = 0;
    int r = 0;

    auto complete = [&](){
        bool ok = true;
        rep(i,7) if(cnt[i] == 0) ok = false;
        return ok;
    };
    
    rep(l,n){
        r = max(l, r);
        while(r < n && !complete()){
            cnt[c[r]]++;
            r++;
        }
        if(complete()) ans += n - r + 1;
        cnt[c[l]]--;
    }

    cout << ans << endl;
    
    return 0;
}
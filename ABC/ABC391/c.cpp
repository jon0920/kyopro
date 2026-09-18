#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;

    int ans = 0;
    vector<int> cnt(n,1), pos(n);
    rep(i,n) pos[i] = i;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int p, h;
            cin >> p >> h;
            p--; h--;
            if(cnt[pos[p]] == 2) ans--;
            cnt[pos[p]]--;

            pos[p] = h;
            cnt[pos[p]]++;
            if(cnt[pos[p]] == 2) ans++;
        }
        else cout << ans << endl;
    }
    
    return 0;
}
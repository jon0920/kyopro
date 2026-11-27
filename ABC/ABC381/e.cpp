#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> pos(3);
    rep(i,n){
        if(s[i] == '1') pos[0].push_back(i);
        else if(s[i] == '2') pos[1].push_back(i);
        else pos[2].push_back(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;

        auto solve = [&](int mid){
            int cnt1 = upper_bound(pos[0].begin(), pos[0].end(), pos[2][mid]) - lower_bound(pos[0].begin(), pos[0].end(), l);
            int cnt2 = lower_bound(pos[1].begin(), pos[1].end(), r) - upper_bound(pos[1].begin(), pos[1].end(), pos[2][mid]);
            return cnt1 >= cnt2;
        };

        auto count = [&](int mid){
            int cnt1 = upper_bound(pos[0].begin(), pos[0].end(), pos[2][mid]) - lower_bound(pos[0].begin(), pos[0].end(), l);
            int cnt2 = lower_bound(pos[1].begin(), pos[1].end(), r) - upper_bound(pos[1].begin(), pos[1].end(), pos[2][mid]);
            return min(cnt1, cnt2);
        };

        int lo = lower_bound(pos[2].begin(), pos[2].end(), l) - pos[2].begin();
        int hi = lower_bound(pos[2].begin(), pos[2].end(), r) - pos[2].begin();

        if(lo == hi){
            cout << 0 << endl;
            continue;
        }
        
        int ok = hi, ng = lo - 1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(solve(mid)) ok = mid;
            else ng = mid;
        }
        
        int ans = 0;
        if(ok < hi){
            ans = count(ok) * 2 + 1;
        }
        if(ok > lo){
            ans = max(ans, count(ok - 1) * 2 + 1);
        }

        cout << ans << endl;
    }
    
    return 0;
}
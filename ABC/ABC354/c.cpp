#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {
    
    int n;
    cin >> n;
    vector<tuple<int,int,int>> tp(n);
    rep(i,n){
        int a, c;
        cin >> a >> c;
        tp[i] = {a, c, i};
    }

    sort(tp.begin(), tp.end(), [](const auto &a, const auto &b){
        auto [aa, ac, ai] = a;
        auto [ba, bc, bi] = b;
        if(aa != ba) return aa > ba;
        return ac < bc;
    });

    pair<int,int> last;
    vector<int> ans;
    rep(i,n){
        auto [na, nc, ni] = tp[i];
        if(i == 0){
            last = {na, nc};
            ans.push_back(ni + 1);
            continue;
        }
        if(last.first <= na || last.second >= nc){
            ans.push_back(ni + 1);
            last = {na, nc};
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
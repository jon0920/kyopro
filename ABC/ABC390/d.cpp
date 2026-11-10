#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> group(n);
    unordered_set<ll> st;    
    auto dfs = [&](auto&& dfs, int idx, int num, ll XOR) -> void {
        if(idx == n){
            st.insert(XOR);
            return;
        }
        rep(i,num){
            ll base = group[i];
            group[i] += a[idx];
            dfs(dfs, idx + 1, num, XOR ^ base ^ group[i]);
            group[i] = base;
        }

        group[num] = a[idx];
        dfs(dfs, idx + 1, num + 1, XOR ^ a[idx]);
        group[num] = 0;
    };

    dfs(dfs, 0, 0, 0);

    cout << st.size() << endl;
    
    return 0;
}
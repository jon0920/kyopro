#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(n);

    vector<int> ans;
    rep(i,k){
        int a, b;
        cin >> a >> b;
        a--;
        cnt[a]++;
        if(cnt[a] == m) ans.push_back(a + 1);
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
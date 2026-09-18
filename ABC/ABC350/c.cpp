#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a;
    rep(i,n){
        int x;
        cin >> x;
        x--;
        a.push_back(x);
    }

    vector<pair<int,int>> ans;
    rep(i,n){
        while(a[i] != i){
            ans.push_back({i + 1, a[i] + 1});
            int tmp = a[a[i]];
            a[a[i]] = a[i];
            a[i] = tmp;
        }
    }
    cout << ans.size() << endl;
    for(auto [a, b] : ans){
        cout << a << " " << b << endl;
    }
    
    return 0;
}
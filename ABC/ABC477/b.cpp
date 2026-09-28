#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    vector<int> ans;
    rep(i,n){
        bool ok = true;
        rep(j,n){
            if(i != j && abs(x[i] - x[j]) < d) ok = false;
        }
        if(ok) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
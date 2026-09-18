#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> r(n);
    rep(i,n) cin >> r[i];

    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(r[i - 1] < r[i] && r[i] > r[i + 1]) ans++;
        if(r[i - 1] > r[i] && r[i] < r[i + 1]) ans++;
    }

    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n - 1);
    rep(i,n) cin >> a[i];
    rep(i,n - 1) cin >> b[i];

    vector<int> res1(n), res2(n);
    res2[0] = 1;
    int ans1 = 0, ans2 = 0;
    rep(i,n - 1){
        res1[i + 1] = (b[i] - res1[i] + 2) % 2;
        res2[i + 1] = (b[i] - res2[i] + 2) % 2;
    }
    rep(i,n){
        if(res1[i] != a[i]) ans1++;
        if(res2[i] != a[i]) ans2++;
    }

    cout << min(ans1, ans2) << endl;
    
    return 0;
}
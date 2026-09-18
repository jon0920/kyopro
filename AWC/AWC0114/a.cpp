#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> pos(101);
    rep(i,n){
        int x, p;
        cin >> x >> p;
        pos[abs(x)] += p;
    }

    int ans = 0;
    int sum = 0;
    rep(r,101){
        sum += pos[r];
        ans = max(ans, sum - (r * r));
    }

    cout << ans << endl;
    
    return 0;
}
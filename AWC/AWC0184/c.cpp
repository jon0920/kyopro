#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    rep(i,m) cin >> d[i];
    sort(d.begin(), d.end());

    rep(i,n){
        int s;
        cin >> s;
        int res = upper_bound(d.begin(), d.end(), s) - d.begin();
        cout << res << endl;
    }
    
    return 0;
}
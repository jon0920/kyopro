#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> w(n - 1);
    rep(i,n - 1) cin >> w[i];

    int ans = 1;
    rep(i,n-1){
        if(w[i] == 0) ans++;
        else{
            if(m > 0){
                ans++;
                m--;
            } else break;
        }
    }

    cout << ans << endl;

    return 0;
}
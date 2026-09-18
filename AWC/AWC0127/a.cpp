#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    ll sum = 0, cnt = 0;
    rep(i,n){
        ll s;
        cin >> s;
        if(s >= k){
            sum += s;
            cnt++;
        }
    }

    if(cnt == 0) cout << -1 << endl;
    else{
        cout << fixed << setprecision(17);
        cout << (double)sum / cnt << endl;
    }
    
    return 0;
}
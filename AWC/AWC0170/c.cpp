#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    set<int> st = {0};
    rep(i,n){
        int a;
        cin >> a;
        set<int> nst = {};
        for(int x : st){
            if(x + a <= 10000) nst.insert(x + a);
            if(x - a >= -10000) nst.insert(x - a);
        }
        st = nst;
    }

    int ans = 1e9;
    for(int x : st) ans = min(ans, abs(x));
    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, t;
    cin >> n >> t;
    bool ans = true;
    rep(i,n){
        int a;
        cin >> a;
        if(a > t) ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;
    
    return 0;
}
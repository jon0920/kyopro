#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b;
    cin >> a >> b;
    vector<bool> c(3, false);
    c[a - 1] = true, c[b - 1] = true;
    if(a == b) cout << -1 << endl;
    else{
        rep(i,3) {
            if(!c[i]) cout << i + 1 << endl;
        }
    }
    
    return 0;
}
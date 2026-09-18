#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<bool> ok(n, true);
    rep(i,m){
        int a;
        char b;
        cin >> a >> b;
        a--;
        if(ok[a] && b == 'M'){
            cout << "Yes" << endl;
            ok[a] = false;
        }
        else cout << "No" << endl;
    }
    
    return 0;
}
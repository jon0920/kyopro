#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    rep(i,n){
        cout << (i < m ? "OK" : "Too Many Requests") << endl;
    }
    
    return 0;
}
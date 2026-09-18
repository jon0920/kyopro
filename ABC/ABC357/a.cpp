#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    rep(i,n){
        int h;
        cin >> h;
        m -= h;
        if(m >= 0) cnt++; 
    }
    cout << cnt << endl;
    
    return 0;
}
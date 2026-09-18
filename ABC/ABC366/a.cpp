#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, t, a;
    cin >> n >> t >> a;
    if(n / 2 < t || n / 2 < a) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<char> s(n);
    rep(i,n) cin >> s[i];

    int q = n - 1;
    int p = 0;
    for(int i = 1; i < n; i++){
        if(s[0] != s[i]) p++;
    }

    int r = gcd(p, q);
    p /= r; q /= r;
    cout << p << '/' << q << endl;
    
    return 0;
}
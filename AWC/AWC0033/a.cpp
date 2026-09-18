#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    int wa = 0;
    rep(i,n) if(s[i] != t[i]) wa++;

    cout << max(0, wa - k) << endl;

    return 0;
}
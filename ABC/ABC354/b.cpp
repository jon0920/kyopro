#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    int sum = 0;
    rep(i,n){
        int c;
        cin >> s[i] >> c;
        sum += c;
    }

    sort(s.begin(), s.end());
    int r = sum % n;
    rep(i,n){
        if(i == r) cout << s[i] << endl;
    }
    
    return 0;
}
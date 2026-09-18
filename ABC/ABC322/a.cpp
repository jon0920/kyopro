#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    rep(i,n - 2){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}
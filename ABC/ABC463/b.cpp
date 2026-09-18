#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    char x;
    cin >> n >> x;
    int pos = x - 'A';
    bool ok = false;
    rep(i,n){
        string s;
        cin >> s;
        if(s[pos] == 'o') ok = true;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
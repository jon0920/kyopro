#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        cout << s[i];
        if(i != n - 1) cout << 'o';
    }
    cout << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    int n;
    cin >> s >> n;
    int sz = s.size();
    rep(i,sz){
        if(i >= n && i <= sz - n - 1) cout << s[i];
    }
    cout << endl;
    
    return 0;
}
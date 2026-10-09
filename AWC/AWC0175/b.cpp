#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, k;
    cin >> h >> w >> k;
    k--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    rep(i,h){
        cout << s[i][k];
    }
    cout << endl;
    
    return 0;
}
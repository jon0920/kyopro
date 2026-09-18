#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;

    int pos1 = 0, pos2 = 0;
    ll ans1 = 0, ans2 = 0;
    rep(i,n * 2){
        if(s[i] == 'A'){
            ans1 += abs(pos1 - i);
            pos1 += 2;
        }
    }
    rep(i,n * 2){
        if(s[i] == 'B'){
            ans2 += abs(pos2 - i);
            pos2 += 2;
        }
    }
    cout << min(ans1, ans2) << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    int cnt = 0;
    rep(i,n) if(s[i] == 'T') cnt++;

    rep(i,m){
        int r;
        cin >> r;
        r--;
        if(s[r] == 'T'){
            cnt--;
            s[r] = 'A';
        } else {
            cnt++;
            s[r] = 'T';
        }
        if(cnt == 0 || cnt == n){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}
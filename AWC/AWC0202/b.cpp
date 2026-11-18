#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt = 0;
    int ans = -1;
    rep(i,n){
        if(s[i] == 'S') cnt++;
        if(cnt == k){
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
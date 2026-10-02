#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, s;
    cin >> n >> s;
    int ans = 0;
    int sum = 0;
    rep(i,n){
        int w;
        cin >> w;
        sum += w;
        if(s <= sum){
            ans++;
            sum = 0;
        }
    }

    cout << ans << endl;
    
    return 0;
}
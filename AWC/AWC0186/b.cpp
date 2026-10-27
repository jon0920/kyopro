#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while(a < c){
        ans++;
        a += b;
    }

    cout << ans << endl;
    
    return 0;
}
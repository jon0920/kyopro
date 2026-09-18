#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        int x = i;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        if(sum == k) ans++;
    }
    cout << ans << endl;

    return 0;
}
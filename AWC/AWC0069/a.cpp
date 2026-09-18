#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    int mx = -1, ans = -1;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        int last;
        cin >> last;
        for(int j = 2; j <= m; j++){
            int a;
            cin >> a;
            sum += abs(a - last);
            last = a;
        }
        if(mx < sum){
            mx = sum;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
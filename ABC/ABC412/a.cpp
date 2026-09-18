#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a < b) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
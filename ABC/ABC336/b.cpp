#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    int cnt = 0;
    while(n > 0){
        if(n % 2 == 0) cnt++;
        else break;
        n /= 2;
    }
    cout << cnt << endl;
    
    return 0;
}
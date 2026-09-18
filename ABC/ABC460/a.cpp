#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    while(1){
        int x = n % m;
        cnt++;
        if(x == 0) break;
        m = x;
    }

    cout << cnt << endl;
    
    return 0;
}
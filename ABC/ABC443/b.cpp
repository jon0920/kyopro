#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    int sum = n;
    n++;
    int cnt = 0;
    while(sum < k){
        sum += n;
        n++;
        cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}
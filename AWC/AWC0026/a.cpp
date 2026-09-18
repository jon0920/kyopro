#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) if(i % k == 0) cout << a[i] << " ";
    cout << endl;

    return 0;
}